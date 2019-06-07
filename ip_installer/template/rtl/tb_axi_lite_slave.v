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
    @TOP_MODULE_NAME@ # (
        .C_S00_AXI_DATA_WIDTH(32),
        .C_S00_AXI_ADDR_WIDTH(32)
    ) @TOP_MODULE_NAME@ (
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

endmodule
