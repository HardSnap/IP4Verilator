// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated.h"

class Vtop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(write_prot,2,0);
    VL_IN8(write_addr_valid,0,0);
    VL_OUT8(write_addr_ready,0,0);
    VL_IN8(write_strb,3,0);
    VL_IN8(write_data_valid,0,0);
    VL_OUT8(write_data_ready,0,0);
    VL_IN8(write_resp_ready,0,0);
    VL_OUT8(write_resp,1,0);
    VL_OUT8(write_resp_valid,0,0);
    VL_IN8(read_prot,2,0);
    VL_IN8(read_addr_valid,0,0);
    VL_OUT8(read_addr_ready,0,0);
    VL_IN8(read_data_ready,0,0);
    VL_OUT8(read_resp,1,0);
    VL_OUT8(read_data_valid,0,0);
    VL_IN(write_addr,31,0);
    VL_IN(write_data,31,0);
    VL_IN(read_addr,31,0);
    VL_OUT(read_data,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
	// Begin mtask footprint  all: 
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__init_reg,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__next_reg,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__mode_reg,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_awready,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_wready,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_bresp,1,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_bvalid,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_arready,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_rresp,1,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_rvalid,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg_wren,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__aw_en,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__a_h_we,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H_we,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_reg,5,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_new,5,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_we,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_inc,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_rst,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_valid_reg,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_valid_new,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_valid_we,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__sha256_ctrl_reg,1,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__sha256_ctrl_new,1,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__sha256_ctrl_we,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_init,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_update,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__state_init,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__state_update,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__first_block,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__ready_flag,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_init,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_next,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_we,0,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_reg,5,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_new,5,0);
	VL_SIG8(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_we,0,0);
	VL_SIGW(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__digest_reg,255,0,8);
	VL_SIGW(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core_block,511,0,16);
	VL_SIGW(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core_digest,255,0,8);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_awaddr,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_araddr,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_rdata,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg0,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg1,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg2,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg3,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg4,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg5,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg6,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg7,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg8,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg9,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg10,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg11,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg12,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg13,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg14,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg15,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg16,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg17,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg18,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg19,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg20,31,0);
    };
    struct {
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg21,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg22,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg23,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg24,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg25,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg26,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg27,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg28,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg29,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg30,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg31,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg32,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg33,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg34,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg35,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg36,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg37,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__reg_data_out,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__byte_index,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__write_mem__DOT__i,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__a_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__a_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__b_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__b_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__c_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__c_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__d_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__d_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__e_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__e_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__f_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__f_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__g_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__g_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__h_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__h_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H0_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H0_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H1_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H1_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H2_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H2_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H3_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H3_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H4_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H4_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H5_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H5_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H6_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H6_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H7_reg,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H7_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t1,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t2,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t1_logic__DOT__sum1,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t1_logic__DOT__ch,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t2_logic__DOT__sum0,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t2_logic__DOT__maj,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__k_constants_inst__DOT__tmp_K,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem00_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem01_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem02_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem03_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem04_new,31,0);
    };
    struct {
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem05_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem06_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem07_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem08_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem09_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem10_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem11_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem12_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem13_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem14_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem15_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_new,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__reg_update__DOT__i,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_0,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_1,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_9,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_14,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__d0,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__d1,31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[16],31,0);
	VL_SIG(top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[16],31,0);
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vtableidx1,5,0);
    VL_SIG8(__Vclklast__TOP__clk_i,0,0);
    VL_SIG8(__Vclklast__TOP__rst_ni,0,0);
    VL_SIG(__Vm_traceActivity,31,0);
    static VL_ST_SIG(__Vtable1_top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__k_constants_inst__DOT__tmp_K[64],31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vtop__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
