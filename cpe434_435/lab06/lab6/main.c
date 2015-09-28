/**
 * Simulated Process Scheduler
 * Christopher Bero [csb0019@uah.edu]
 * Lab 6 - CPE 435
 *
 * RR - Round Robin
 * PP - Priority Processing
 */

#include <stdio.h>
#include <stdlib.h>

// Other common headers
#include <string.h> 	// For manipulating string and char* types
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>	// IPC - Inter Process Communication
#include <sys/shm.h> 	// SHM - message queue
#include <sys/msg.h>	// MSG - Message Queues

// Process Struct
typedef struct process {
	int pid; 	/* Process ID; RR and PP */
	int burst; 	/* Time process requires to complete; RR and PP */
	int t_round; /* Turn around time. Total time needed for process to complete (working + waiting); RR and PP */

	int working; /* Working time, amount of burst done so far; RR only */
	//int waiting; /* waiting time; rr only */

	int priority; /* Process priority; PP only */

	struct process * next; /* Access the next process in the list */
	struct process * prev; /* Acces the previous process; PP only */
} process;

process * initProc ()
{
	process * newProc;
	newProc = (process*)malloc(sizeof(process));
	newProc->pid = -1;
	newProc->burst = -1;
	newProc->t_round = 0;
	newProc->working = 0;
	//newProc->waiting = 0;
	newProc->priority = 0;
	newProc->next = NULL;
	newProc->prev = NULL;
	return(newProc);
}

/**
 * rmNewline
 * Strips the ending '\n' char from an array
 */
void rmNewline (char * string)
{
	// Variables
	int index;
	index = 0;

	// Iterate through char array until end
	while (string[index] != '\n' && string[index] != '\0')
	{
		index++;
	}
	string[index] = '\0';
}

/**
 * Prompt
 * Prints a prompt, reads user input
 */
int prompt(char * input, short unsigned int input_len)
{
	// Collect and Verify input
	if (fgets(input, input_len, stdin) == NULL)
	{
		return(-1);
	}
	rmNewline(input);
	return(0);
}

/**
 * strToInt
 * Checks that all chars in a str/array are digits
 * then converts them to an int
 * Returns 0 on success.
 */
//int strToInt (char * string, int * output)
//{
//	// Variables
//	unsigned int index;
//	index = 0;
//
//	while (string[index] != '\0')
//	{
//		if (isdigit(string[index]) == 0)
//		{
//			// not a digit
//			return(-1);
//		}
//		index++;
//	}
//	// All chars should be digits
//	*output = atoi(string);
//	return(0);
//}
int strToInt (char * string)
{
	// Variables
	unsigned int index;
	index = 0;

	while (string[index] != '\0')
	{
		if (isdigit(string[index]) == 0)
		{
			// not a digit
			return(-1);
		}
		index++;
	}
	// All chars should be digits
	return(atoi(string));
}

/**
 * closeAll
 * close shm and free pointers
 */
void closeAll (process * rootProc, char * time_unit, char * input_string)
{
	process * thisProc;
	process * nextProc;
	thisProc = rootProc;
	while (1)
	{
		//printf("\nFreeing pid: %d", thisProc->pid);
		if (thisProc->next == NULL)
		{
			free(thisProc);
			break;
		}
		nextProc = thisProc->next;
		fflush(stdout);
		free(thisProc);
		thisProc = nextProc;
	}

	free(input_string);
	free(time_unit);
}

void updateRound (process * rootProc, process * workProc, int quantum)
{
	process * thisProc;
	thisProc = rootProc;
	while (1)
	{
		if (thisProc->working < thisProc->burst || thisProc == workProc)
			thisProc->t_round += quantum;
		if (thisProc->next == NULL)
			break;
		thisProc = thisProc->next;
	}
}

int rrDone (process * rootProc)
{
	process * thisProc;
	thisProc = rootProc;
	while (1)
	{
		if (thisProc->working < thisProc->burst)
		{
			return(0);
		}
		if (thisProc->next == NULL)
			break;
		thisProc = thisProc->next;
	}
	return(1);
}

int main( int argc, char *argv[] )
{
	// Variables
	char * input_string;				/* User input */
	short unsigned int input_string_size = 100;/* Length of user input array */
	unsigned int time_quantum = 1;		/* Base unit of processing time */
	char * time_unit;					/* time unit being used */
	short unsigned int time_unit_size = 25; /* Allows for answers like "ms" or "milliseconds" */
	unsigned short int isProcRR = 1; 	/* Are we processing Round Robin? Otherwise priority */
	process * rootProc = NULL;			/* Root of single/double linked list */
	process * prevProc = NULL;
	process * thisProc = NULL;
	int time = 0;
	int totalWait = 0;
	int numProcs = 1;
	double avgWait = 0;

	// Initialize
	input_string = (char*)malloc(sizeof(char) * input_string_size);
	time_unit = (char*)malloc(sizeof(char) * time_unit_size);
	rootProc = initProc();

	// Determine what role this process has
	printf("\nAre we scheduling with (R)ound Robin or (P)riority Processing? (r/p) >");
	if (prompt(input_string, input_string_size) != 0)
	{
		printf("\nError collecting user input. Exiting.\n");
		//closeAll(msgId, input_string);
		return(-1);
	}
	if (input_string[0] == 'r' || input_string[0] == 'R')
	{
		printf("\nOK, I will schedule the tasks as Round Robin.");
		isProcRR = 1;
	}
	else if (input_string[0] == 'p' || input_string[0] == 'P')
	{
		printf("\nOK, I will schedule the tasks as Priority Processing.");
		isProcRR = 0;
		printf("\nOh no! This isn't implemented yet!\n");
		return(-1);
	}
	else
	{
		printf("\nInput doesn't seem to be any of 'r', 'R', 'p', 'P'. Exiting.\n");
		return(-1);
	}

	// Determine time units
	printf("\nWhat time units are we dealing with? (ms, ns, ps, etc) >");
	if (prompt(time_unit, input_string_size) != 0)
	{
		printf("\nError collecting user input. Exiting.\n");
		//closeAll(msgId, input_string);
		return(-1);
	}


	// Set quantum of Round Robin
	if (isProcRR)
	{
		printf("\nPlease enter the number of %s for our time quantum >", time_unit);
		if (prompt(input_string, input_string_size) != 0)
		{
			printf("\nError collecting user input. Exiting.\n");
			//closeAll(msgId, input_string);
			return(-1);
		}
		else
		{
			time_quantum = strToInt(input_string);
			if (time_quantum <= 0)
			{
				printf("\nError, invalid ascii to int conversion. Exiting.\n");
				//closeAll(msgId, input_string);
				return(-1);
			}
		}
		printf("\nType: Round Robin, time units: %s, time quantum: %d", time_unit, time_quantum);
	}


	// Collect first process PID
	printf("\nPlease enter the PID of the first process >");
	if (prompt(input_string, input_string_size) != 0)
	{
		printf("\nError collecting user input. Exiting.\n");
		//closeAll(msgId, input_string);
		return(-1);
	}
	else
	{
		rootProc->pid = strToInt(input_string);
		if (rootProc->pid <= 0)
		{
			printf("\nError, invalid ascii to int conversion. Exiting.\n");
			//closeAll(msgId, input_string);
			return(-1);
		}
	}

	// Collect first process burst
	printf("\nPlease enter the burst time of the first process >");
	if (prompt(input_string, input_string_size) != 0)
	{
		printf("\nError collecting user input. Exiting.\n");
		//closeAll(msgId, input_string);
		return(-1);
	}
	else
	{
		rootProc->burst = strToInt(input_string);
		if (rootProc->burst <= 0)
		{
			printf("\nError, invalid ascii to int conversion. Exiting.\n");
			//closeAll(msgId, input_string);
			return(-1);
		}
	}

	// Continue collecting PID/Burst pairs until -1 is entered for a PID.
	prevProc = rootProc;
	while (1)
	{
		int pid = 0;
		printf("\nPlease enter the PID of the next process (-1 to finish) >");
		if (prompt(input_string, input_string_size) != 0)
		{
			printf("\nError collecting user input. Exiting.\n");
			//closeAll(msgId, input_string);
			return(-1);
		} else {
			pid = strToInt(input_string);
		}
		if (pid < 0)
		{
			printf("\nDone inputting processes.");
			break;
		}
		thisProc = initProc(); // Initialize new process
		numProcs++; // Increment number of processes
		thisProc->pid = pid; // Set the pid
		printf("\nPlease enter the burst time of the next process >");
		if (prompt(input_string, input_string_size) != 0)
		{
			printf("\nError collecting user input. Exiting.\n");
			//closeAll(msgId, input_string);
			return(-1);
		}
		else
		{
			thisProc->burst = strToInt(input_string);
			if (thisProc->burst <= 0)
			{
				printf("\nError, invalid ascii to int conversion. Exiting.\n");
				//closeAll(msgId, input_string);
				return(-1);
			}
		}
		prevProc->next = thisProc;
		thisProc->prev = prevProc;
		prevProc = thisProc;
	}

	// Print all process's
	thisProc = rootProc;
	while (1)
	{
		printf("\nPID: %d Burst: %d", thisProc->pid, thisProc->burst);
		if (thisProc->next == NULL)
			break;
		thisProc = thisProc->next;
	}
	printf("\n");

	// Simulate scheduling
	if (isProcRR)
	{
		thisProc = rootProc;
		while (1)
		{
			int localQuantum;
			printf("\n=====");
			printf("\nBegin time: %d%s.", time, time_unit);

			if (thisProc->working + time_quantum >= thisProc->burst)
			{
				localQuantum = thisProc->burst - thisProc->working;
			}
			else
			{
				localQuantum = time_quantum;
			}
			thisProc->working += localQuantum;
			time += localQuantum;
			updateRound(rootProc, thisProc, localQuantum);

			printf(" Pid %d worked for %d%s", thisProc->pid, localQuantum, time_unit);
			printf("\nAll other processes accumulated %d%s of wait time.", localQuantum, time_unit);

			printf("\nEnd time: %d%s.", time, time_unit);
			fflush(stdout);

			if (rrDone(rootProc) == 1)
			{
				break;
			}

			if (thisProc->next == NULL)
			{
				thisProc = rootProc;
			} else {
				thisProc = thisProc->next;
			}
		}
	}
	else
	{
		//
	}
	printf("\n");

	// Print process summary
	thisProc = rootProc;
	while (1)
	{
		if (isProcRR)
		{
			printf("\nPID: %d Burst: %d%s Working: %d%s t_round: %d%s",
				thisProc->pid, thisProc->burst, time_unit, thisProc->working, time_unit, thisProc->t_round, time_unit);
		}
		else
		{
			printf("\nPID: %d Burst: %d%s t_round: %d%s",
				thisProc->pid, thisProc->burst, time_unit, thisProc->t_round, time_unit);
		}

		if (thisProc->next == NULL)
		{
			break;
		}
		thisProc = thisProc->next;
	}

	// Calculate stats
	thisProc = rootProc;
	while (1)
	{
		totalWait += thisProc->t_round - thisProc->burst;
		if (thisProc->next == NULL)
			break;
		thisProc = thisProc->next;
		numProcs++;
	}
	avgWait = ((double)totalWait / numProcs);
	printf("\nAverage wait time: %lf%s", avgWait, time_unit);

	// Close
	closeAll(rootProc, time_unit, input_string);

	printf("\n");

    return 0;
}
