//-uarec Module ---------------------------------------------------
// Universal serial reciever module.
// Function is to input asynchronous serial data that is being sent at
// 16 times slower than the frequency rate of the enabling input. It
// then converts this data into parallel form and sends a single cycle
// positive pulse with the output is valid. This pulse has a width that
// is the same as the period as the master clock that drives the module.
// Inputs:
//    en -- enabling signal one master
//          clock period in duration 
//          sent at a frequency that is 16 
//          times the operational baud rate.
//    clk -- master (global) clock
//    ser_in -- data input line to be sampled
// Outputs:
//    dout -- 8 bit data output bus
//    en_out -- active high data valid signal
module uarec(input en,clk,ser_in,output en_out, output [7:0] dout);

    wire n0,n1,n2,n3;

    cycle_count_16    C1(.en(en),.clk(clk),.r(n0),.h(n1),.f(n2));

    rec_control_logic C2(.d(ser_in),.clk(clk),.en(en),.h(n1),.f(n2),
                         .s(n3),.l(en_out),.r(n0));

    shift_reg_8_en    C3(.din(ser_in),.clk(clk),.en(n3),.dout(dout));

endmodule

//-cycle_count_16 Module-------------------------------------------
//  16 Count Countdown Timer
//  After Reset this Counter proceeds 
//     8 clock cycles before asserting the H Flag (Half Count Flag)
//     16 clock cycles before asserting the F Flag (Full Count Flag)
//  Inputs:  clk -- Rising Edge Clock
//           r -- Synchronous Reset
//  Outputs: h -- Half Count Flag -- Active High
//           f -- Full Count Flag -- Active High 
//  B. Earl Wells, UAH, February 10, 2015
module cycle_count_16(input en,clk,r, output reg h,f);
   reg [4:0] count;
   always @(posedge clk)
      if (en)
         begin
            h=0; // set up defaults for
            f=0; // outputs h and f
            if (r) count=15;
            else
               if (count)
                  count=count-1;
               if (count <= 7)
                  h=1;    // half count reached
               if (!count)
                  f=1;    // full count reached
         end
endmodule

//-rec_control_logic Module----------------------------------------
// This is the main receiver control logic module that is to be 
// developed by cpe324 for the laboratory assignment  
module rec_control_logic(input d,clk,en,h,f,output reg s,l,r);

   reg [3:0] state,next_state; // may want to use these
	
	parameter S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4, S5 = 5, S6 = 6, S7 = 7, S8 = 8, S9 = 9, S10 = 10;
	
	always @ (posedge clk)
	begin
		//next_state = state;
		
		case (state)
			S0:
				begin
				if (en==1 && d==0)
					begin
					r = 1'b1;
					s = 1'b0;
					l = 1'b0;
					next_state = S1;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && d==1)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S1:
				begin
				if (en && (d==0 && h==1))
					begin
					r = 1'b1;
					s = 1'b0;
					l = 1'b0;
					next_state = S2;
					end
				else if (en==1 && d==1)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					next_state = S0;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && (d==0 && h==0))
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S2:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S3;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S3:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S4;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S4:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S5;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S5:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S6;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S6:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S7;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S7:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S8;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S8:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S9;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S9:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b1;
					s = 1'b1;
					l = 1'b0;
					next_state = S10;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
			S10:
				begin
				if (en==1 && f==1)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b1;
					next_state = S0;
					end
				else if (en==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				else if (en==1 && f==0)
					begin
					r = 1'b0;
					s = 1'b0;
					l = 1'b0;
					end
				end
		endcase
		state = next_state;
	end
				 
endmodule

//-shift_reg_8_en Module-------------------------------------------
// Enabled 8-bit shift register where data is assumed to be
// shifted in Least Significant Bit (LSB) first.
// Inputs: 
//    din -- serial data input
//    clk -- global clock
//    en  -- clock enable input (active high)
// Output:
//    dout -- eight bit data output
module shift_reg_8_en(input din,clk,en,output reg [7:0] dout);
   always @ (posedge clk)
      if (en) dout = {din,dout[7:1]};
endmodule

