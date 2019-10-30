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

    //select target
    input wire [1:0] target_selector,

    //Write Address channel (AW)
    input reg [31:0] write_addr, //Master write address
    input reg [2:0] write_prot,	 //type of write(leave at 0)
    input reg write_addr_valid,	 //master indicating address is valid
    output wire write_addr_ready,//slave ready to receive address

    //Write Data Channel (W)
    input reg [31:0] write_data, //Master write data
    input reg [3:0] write_strb,	 //Master byte-wise write strobe
    input reg write_data_valid,	 //Master indicating write data is valid
    output wire write_data_ready,//slave ready to receive data

    //Write Response Channel (WR)
    input reg write_resp_ready,   //Master ready to receive write response
    output wire [1:0] write_resp, //slave write response
    output wire write_resp_valid, //slave response valid

    //Read Address channel (AR)
    input reg [31:0] read_addr,  //Master read address
    input reg [2:0] read_prot,	 //type of read(leave at 0)
    input reg read_addr_valid,	 //Master indicating address is valid
    output wire read_addr_ready, //slave ready to receive address

    //Read Data Channel (R)
    input reg read_data_ready,	  //Master indicating ready to receive data
    output wire [31:0] read_data,	//slave read data
    output wire [1:0] read_resp, 	//slave read response
    output wire read_data_valid,  //slave indicating data in channel is valid

    output wire irq_ack,
    output wire irq_rq
  );

  reg [31:0] write_addr_sha;
  reg [2:0]  write_prot_sha;
  reg  write_addr_valid_sha;
  reg [31:0] write_data_sha;
  reg  [3:0] write_strb_sha;
  reg  write_data_valid_sha;
  reg  write_data_ready_sha;
  reg  write_resp_ready_sha;
  reg  [31:0] read_addr_sha;
  reg   [2:0] read_prot_sha;
  reg   read_addr_valid_sha;
  reg   read_data_ready_sha;	
  
  reg  [1:0] write_resp_sha; // output
  reg  write_resp_valid_sha; // output  
  reg   read_addr_ready_sha; // output 
  reg  write_addr_ready_sha; // output
  reg  [31:0] read_data_sha; // output
  reg   [1:0] read_resp_sha; // output 
  reg   read_data_valid_sha; // output

  reg [31:0] write_addr_aes;
  reg [2:0]  write_prot_aes;
  reg  write_addr_valid_aes;
  reg [31:0] write_data_aes;
  reg  [3:0] write_strb_aes;
  reg  write_data_valid_aes;
  reg  write_data_ready_aes;
  reg  write_resp_ready_aes;
  reg  [31:0] read_addr_aes;
  reg   [2:0] read_prot_aes;
  reg   read_addr_valid_aes;
  reg   read_data_ready_aes;	

  reg  [1:0] write_resp_aes; // output
  reg  write_resp_valid_aes; // output  
  reg   read_addr_ready_aes; // output 
  reg  write_addr_ready_aes; // output
  reg  [31:0] read_data_aes; // output
  reg   [1:0] read_resp_aes; // output 
  reg   read_data_valid_aes; // output

  reg [31:0] write_addr_pic;
  reg [2:0]  write_prot_pic;
  reg  write_addr_valid_pic;
  reg [31:0] write_data_pic;
  reg  [3:0] write_strb_pic;
  reg  write_data_valid_pic;
  reg  write_data_ready_pic;
  reg  write_resp_ready_pic;
  reg  [31:0] read_addr_pic;
  reg   [2:0] read_prot_pic;
  reg   read_addr_valid_pic;
  reg   read_data_ready_pic;	

  reg  [1:0] write_resp_pic; // output
  reg  write_resp_valid_pic; // output  
  reg   read_addr_ready_pic; // output 
  reg  write_addr_ready_pic; // output
  reg  [31:0] read_data_pic; // output
  reg   [1:0] read_resp_pic; // output 
  reg   read_data_valid_pic; // output

  reg  [1:0] write_resp_reg; // output
  reg  write_resp_valid_reg; // output  
  reg   read_addr_ready_reg; // output 
  reg  write_addr_ready_reg; // output
  reg  [31:0] read_data_reg; // output
  reg   [1:0] read_resp_reg; // output 
  reg   read_data_valid_reg; // output

  wire sha_interrupt;
  wire aes_interrupt;

  always @( target_selector )
  begin
    case ( target_selector )

      2'b00: begin
          write_addr_sha       = write_addr;
          write_prot_sha       = write_prot;
          write_addr_valid_sha = write_addr_valid;
          write_data_sha       = write_data;
          write_strb_sha       = write_strb;
          write_data_valid_sha = write_data_valid;
          write_data_ready_sha = write_data_ready;
          write_resp_ready_sha = write_resp_ready;
          read_addr_sha        = read_addr;
          read_prot_sha        = read_prot;
          read_addr_valid_sha  = read_addr_valid;
          read_data_ready_sha  = read_data_ready;	

          write_resp_reg       = write_resp_sha      ; // output
          write_resp_valid_reg = write_resp_valid_sha; // output  
          read_addr_ready_reg  = read_addr_ready_sha ; // output 
          write_addr_ready_reg = write_addr_ready_sha; // output
          read_data_reg        = read_data_sha       ; // output
          read_resp_reg        = read_resp_sha       ; // output 
          read_data_valid_reg  = read_data_valid_sha ; // output      
        end

      2'b01: begin
          write_addr_aes       = write_addr;
          write_prot_aes       = write_prot;
          write_addr_valid_aes = write_addr_valid;
          write_data_aes       = write_data;
          write_strb_aes       = write_strb;
          write_data_valid_aes = write_data_valid;
          write_data_ready_aes = write_data_ready;
          write_resp_ready_aes = write_resp_ready;
          read_addr_aes        = read_addr;
          read_prot_aes        = read_prot;
          read_addr_valid_aes  = read_addr_valid;
          read_data_ready_aes  = read_data_ready;	
          
          write_resp_reg       = write_resp_aes      ; // output
          write_resp_valid_reg = write_resp_valid_aes; // output  
          read_addr_ready_reg  = read_addr_ready_aes ; // output 
          write_addr_ready_reg = write_addr_ready_aes; // output
          read_data_reg        = read_data_aes       ; // output
          read_resp_reg        = read_resp_aes       ; // output 
          read_data_valid_reg  = read_data_valid_aes ; // output      
      end
     
      2'b10: begin
          write_addr_pic       = write_addr;
          write_prot_pic       = write_prot;
          write_addr_valid_pic = write_addr_valid;
          write_data_pic       = write_data;
          write_strb_pic       = write_strb;
          write_data_valid_pic = write_data_valid;
          write_data_ready_pic = write_data_ready;
          write_resp_ready_pic = write_resp_ready;
          read_addr_pic        = read_addr;
          read_prot_pic        = read_prot;
          read_addr_valid_pic  = read_addr_valid;
          read_data_ready_pic  = read_data_ready;	
          
          write_resp_reg       = write_resp_pic      ; // output
          write_resp_valid_reg = write_resp_valid_pic; // output  
          read_addr_ready_reg  = read_addr_ready_pic ; // output 
          write_addr_ready_reg = write_addr_ready_pic; // output
          read_data_reg        = read_data_pic       ; // output
          read_resp_reg        = read_resp_pic       ; // output 
          read_data_valid_reg  = read_data_valid_pic ; // output 
      end

      2'b11: begin
      end

    endcase 
    end

    assign write_resp       = write_resp_reg      ; // output
    assign write_resp_valid = write_resp_valid_reg; // output  
    assign read_addr_ready  = read_addr_ready_reg ; // output 
    assign write_addr_ready = write_addr_ready_reg; // output
    assign read_data        = read_data_reg       ; // output
    assign read_resp        = read_resp_reg       ; // output 
    assign read_data_valid  = read_data_valid_reg ; // output      


    //Instantiation of LED IP
    AES_CTR_v1_0 # (
        .C_S00_AXI_DATA_WIDTH(32),
        .C_S00_AXI_ADDR_WIDTH(32)
    ) AES_CTR_v1_0 (
        .s00_axi_aclk(clk_i),
        .s00_axi_aresetn(rst_ni),

        .s00_axi_awaddr(write_addr_aes),
        .s00_axi_awprot(write_prot_aes),
        .s00_axi_awvalid(write_addr_valid_aes),
        .s00_axi_awready(write_addr_ready_aes),

        .s00_axi_wdata(write_data_aes),
        .s00_axi_wstrb(write_strb_aes),
        .s00_axi_wvalid(write_data_valid_aes),
        .s00_axi_wready(write_data_ready_aes),

        .s00_axi_bresp(write_resp_aes),
        .s00_axi_bvalid(write_resp_valid_aes),
        .s00_axi_bready(write_resp_ready_aes),

        .s00_axi_araddr(read_addr_aes),
        .s00_axi_arprot(read_prot_aes),
        .s00_axi_arvalid(read_addr_valid_aes),
        .s00_axi_arready(read_addr_ready_aes),

        .s00_axi_rdata(read_data_aes),
        .s00_axi_rresp(read_resp_aes),
        .s00_axi_rvalid(read_data_valid_aes),
        .s00_axi_rready(read_data_ready_aes),

        .interrupt(aes_interrupt)
    );

    //Instantiation of LED IP
    sha256_v1_0 # (
        .C_S00_AXI_DATA_WIDTH(32),
        .C_S00_AXI_ADDR_WIDTH(32)
    ) sha256_v1_0 (
        .s00_axi_aclk(clk_i),
        .s00_axi_aresetn(rst_ni),

        .s00_axi_awaddr(write_addr_sha),
        .s00_axi_awprot(write_prot_sha),
        .s00_axi_awvalid(write_addr_valid_sha),
        .s00_axi_awready(write_addr_ready_sha),

        .s00_axi_wdata(write_data_sha),
        .s00_axi_wstrb(write_strb_sha),
        .s00_axi_wvalid(write_data_valid_sha),
        .s00_axi_wready(write_data_ready_sha),

        .s00_axi_bresp(write_resp_sha),
        .s00_axi_bvalid(write_resp_valid_sha),
        .s00_axi_bready(write_resp_ready_sha),

        .s00_axi_araddr(read_addr_sha),
        .s00_axi_arprot(read_prot_sha),
        .s00_axi_arvalid(read_addr_valid_sha),
        .s00_axi_arready(read_addr_ready_sha),

        .s00_axi_rdata(read_data_sha),
        .s00_axi_rresp(read_resp_sha),
        .s00_axi_rvalid(read_data_valid_sha),
        .s00_axi_rready(read_data_ready_sha),

        .interrupt(sha_interrupt)
      );


	pic_axi_interface # ( 
		.C_S_AXI_DATA_WIDTH(32),
		.C_S_AXI_ADDR_WIDTH(32)
	) pic_axi_interface_inst (
    .interrupt_request({sha_interrupt, 7'b0000000}), //interrupt5, interrupt4, interrupt3, interrupt2, interrupt1, interrupt0}),
    .irq_ack(irq_ack),
    .irq_rq(irq_rq),

   .S_AXI_ACLK   (clk_i),
   .S_AXI_ARESETN(rst_ni),
   .S_AXI_AWADDR (write_addr_pic),
   .S_AXI_AWPROT (write_prot_pic),
   .S_AXI_AWVALID(write_addr_valid_pic),
   .S_AXI_AWREADY(write_addr_ready_pic),
   .S_AXI_WDATA  (write_data_pic),
   .S_AXI_WSTRB  (write_strb_pic),
   .S_AXI_WVALID (write_data_valid_pic),
   .S_AXI_WREADY (write_data_ready_pic),
   .S_AXI_BRESP  (write_resp_pic),
   .S_AXI_BVALID (write_resp_valid_pic),
   .S_AXI_BREADY (write_resp_ready_pic),
   .S_AXI_ARADDR (read_addr_pic),
   .S_AXI_ARPROT (read_prot_pic),
   .S_AXI_ARVALID(read_addr_valid_pic),
   .S_AXI_ARREADY(read_addr_ready_pic),
   .S_AXI_RDATA  (read_data_pic),
   .S_AXI_RRESP  (read_resp_pic),
   .S_AXI_RVALID (read_data_valid_pic),
   .S_AXI_RREADY (read_data_ready_pic)
	);


endmodule
