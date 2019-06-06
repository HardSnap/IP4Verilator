`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 05/27/2019 02:40:47 PM
// Design Name:
// Module Name: tb_axi_lite_slave
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////

module top(
    //clock and reset_n signals
    input wire clk_i,
    input wire rst_ni,

    //Write Address channel (AW)
    input reg [31:0] write_addr, //Master write address
    input reg [2:0] write_prot,	 //type of write(leave at 0)
    input reg write_addr_valid,	 //master indicating address is valid
    output wire write_addr_ready, //slave ready to receive address

    //Write Data Channel (W)
    input reg [31:0] write_data, //Master write data
    input reg [3:0] write_strb,	 //Master byte-wise write strobe
    input reg write_data_valid,	 //Master indicating write data is valid
    output wire write_data_ready, //slave ready to receive data

    //Write Response Channel (WR)
    input reg write_resp_ready,//Master ready to receive write response
    output wire [1:0] write_resp,		  //slave write response
    output wire write_resp_valid,		  //slave response valid

    //Read Address channel (AR)
    input reg [31:0] read_addr,//Master read address
    input reg [2:0] read_prot,	 //type of read(leave at 0)
    input reg read_addr_valid,	 //Master indicating address is valid
    output wire read_addr_ready,		     //slave ready to receive address

    //Read Data Channel (R)
    input reg read_data_ready,	//Master indicating ready to receive data
    output wire [31:0] read_data,	   	//slave read data
    output wire [1:0] read_resp,	    	//slave read response
    output wire read_data_valid		    //slave indicating data in channel is valid
  );

    //Instantiation of LED IP
    sha256_v1_0 # (
        .C_S00_AXI_DATA_WIDTH(32),
        .C_S00_AXI_ADDR_WIDTH(32)
    ) sha256_v1_0 (
        .s00_axi_aclk(clk_i),
        .s00_axi_aresetn(rst_ni),

        .s00_axi_awaddr(write_addr),
        .s00_axi_awprot(write_prot),
        .s00_axi_awvalid(write_addr_valid),
        .s00_axi_awready(write_addr_ready),

        .s00_axi_wdata(write_data),
        .s00_axi_wstrb(write_strb),
        .s00_axi_wvalid(write_data_valid),
        .s00_axi_wready(write_data_ready),

        .s00_axi_bresp(write_resp),
        .s00_axi_bvalid(write_resp_valid),
        .s00_axi_bready(write_resp_ready),

        .s00_axi_araddr(read_addr),
        .s00_axi_arprot(read_prot),
        .s00_axi_arvalid(read_addr_valid),
        .s00_axi_arready(read_addr_ready),

        .s00_axi_rdata(read_data),
        .s00_axi_rresp(read_resp),
        .s00_axi_rvalid(read_data_valid),
        .s00_axi_rready(read_data_ready)
    );

	//clock signal
	// always
	// 	#5 aclk <=~aclk;

	// integer i;
	// initial
	// begin
  //  		arstn = 0;
	// 	i=0;
	// 	#10 arstn=1;
	// 	//for(i=0;i<=32'hF;i=i+1)
  //
	// 	#1 axi_write(32'd20,32'h61626380);
	// 	#1 axi_write(32'd24,32'h00000000);
	// 	#1 axi_write(32'd28,32'h00000000);
	// 	#1 axi_write(32'd32,32'h00000000);
	// 	#1 axi_write(32'd36,32'h00000000);
	// 	#1 axi_write(32'd40,32'h00000000);
	// 	#1 axi_write(32'd44,32'h00000000);
	// 	#1 axi_write(32'd48,32'h00000000);
	// 	#1 axi_write(32'd52,32'h00000000);
	// 	#1 axi_write(32'd56,32'h00000000);
	// 	#1 axi_write(32'd60,32'h00000000);
	// 	#1 axi_write(32'd64,32'h00000000);
	// 	#1 axi_write(32'd68,32'h00000000);
	// 	#1 axi_write(32'd72,32'h00000000);
	// 	#1 axi_write(32'd76,32'h00000000);
	// 	#1 axi_write(32'd80,32'h00000018);
  //
	// 	#1 axi_write(32'd4,32'h00000005);
	// 	#1 axi_write(32'd4,32'h00000004);
  //
  //       #20
  //
	// 	$finish;
	// end
  //
  //
	// task axi_write;
	// input [31:0] addr;
	// input [31:0] data;
	// begin
	// 	#3 write_addr <= addr;	//Put write address on bus
	// 	write_data <= data;	//put write data on bus
	// 	write_addr_valid <= 1'b1;	//indicate address is valid
	// 	write_data_valid <= 1'b1;	//indicate data is valid
	// 	write_resp_ready <= 1'b1;	//indicate ready for a response
	// 	write_strb <= 4'hF;		//writing all 4 bytes
  //
	// 	//wait for one slave ready signal or the other
	// 	wait(write_data_ready || write_addr_ready);
  //
	// 	@(posedge aclk); //one or both signals and a positive edge
	// 	if(write_data_ready&&write_addr_ready)//received both ready signals
	// 	begin
	// 		write_addr_valid<=0;
	// 		write_data_valid<=0;
	// 	end
	// 	else    //wait for the other signal and a positive edge
	// 	begin
	// 		if(write_data_ready)    //case data handshake completed
	// 		begin
	// 			write_data_valid<=0;
	// 			wait(write_addr_ready); //wait for address address ready
	// 		end
  //           		else if(write_addr_ready)   //case address handshake completed
  //           		begin
	// 			write_addr_valid<=0;
  //               		wait(write_data_ready); //wait for data ready
  //           		end
	// 		@ (posedge aclk);// complete the second handshake
	// 		write_addr_valid<=0; //make sure both valid signals are deasserted
	// 		write_data_valid<=0;
	// 	end
  //
	// 	//both handshakes have occured
	// 	//deassert strobe
	// 	write_strb<=0;
  //
	// 	//wait for valid response
	// 	wait(write_resp_valid);
  //
	// 	//both handshake signals and rising edge
	// 	@(posedge aclk);
  //
	// 	//deassert ready for response
	// 	write_resp_ready<=0;
  //
  //
	// 	//end of write transaction
	// end
	// endtask;

endmodule
