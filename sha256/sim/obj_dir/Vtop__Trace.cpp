// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgArray(c+1,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core_block),512);
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+17,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__ready_flag));
	vcdp->chgArray(c+18,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core_digest),256);
	vcdp->chgBus(c+26,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__reg_data_out),32);
	vcdp->chgBus(c+27,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__a_new),32);
	vcdp->chgBus(c+28,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__b_new),32);
	vcdp->chgBus(c+29,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__c_new),32);
	vcdp->chgBus(c+30,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__d_new),32);
	vcdp->chgBus(c+31,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__e_new),32);
	vcdp->chgBus(c+32,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__f_new),32);
	vcdp->chgBus(c+33,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__g_new),32);
	vcdp->chgBus(c+34,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__h_new),32);
	vcdp->chgBit(c+35,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__a_h_we));
	vcdp->chgBus(c+36,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H0_new),32);
	vcdp->chgBus(c+37,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H1_new),32);
	vcdp->chgBus(c+38,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H2_new),32);
	vcdp->chgBus(c+39,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H3_new),32);
	vcdp->chgBus(c+40,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H4_new),32);
	vcdp->chgBus(c+41,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H5_new),32);
	vcdp->chgBus(c+42,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H6_new),32);
	vcdp->chgBus(c+43,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H7_new),32);
	vcdp->chgBit(c+44,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H_we));
	vcdp->chgBus(c+45,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_new),6);
	vcdp->chgBit(c+46,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_we));
	vcdp->chgBit(c+47,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_inc));
	vcdp->chgBit(c+48,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_rst));
	vcdp->chgBit(c+49,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_valid_new));
	vcdp->chgBit(c+50,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_valid_we));
	vcdp->chgBus(c+51,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__sha256_ctrl_new),2);
	vcdp->chgBit(c+52,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__sha256_ctrl_we));
	vcdp->chgBit(c+53,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_init));
	vcdp->chgBit(c+54,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_update));
	vcdp->chgBit(c+55,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__state_init));
	vcdp->chgBit(c+56,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__state_update));
	vcdp->chgBit(c+57,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__first_block));
	vcdp->chgBus(c+58,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t1),32);
	vcdp->chgBus(c+59,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t2),32);
	vcdp->chgBus(c+60,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__k_constants_inst__DOT__tmp_K),32);
	vcdp->chgBit(c+61,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_init));
	vcdp->chgBit(c+62,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_next));
	vcdp->chgBus(c+63,(((0x10U > (IData)(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_reg))
			     ? vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem
			    [(0xfU & (IData)(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_reg))]
			     : vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_new)),32);
	vcdp->chgBus(c+64,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t1_logic__DOT__sum1),32);
	vcdp->chgBus(c+65,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t1_logic__DOT__ch),32);
	vcdp->chgBus(c+66,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t2_logic__DOT__sum0),32);
	vcdp->chgBus(c+67,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t2_logic__DOT__maj),32);
	vcdp->chgBus(c+68,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem00_new),32);
	vcdp->chgBus(c+69,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem01_new),32);
	vcdp->chgBus(c+70,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem02_new),32);
	vcdp->chgBus(c+71,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem03_new),32);
	vcdp->chgBus(c+72,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem04_new),32);
	vcdp->chgBus(c+73,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem05_new),32);
	vcdp->chgBus(c+74,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem06_new),32);
	vcdp->chgBus(c+75,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem07_new),32);
	vcdp->chgBus(c+76,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem08_new),32);
	vcdp->chgBus(c+77,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem09_new),32);
	vcdp->chgBus(c+78,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem10_new),32);
	vcdp->chgBus(c+79,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem11_new),32);
	vcdp->chgBus(c+80,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem12_new),32);
	vcdp->chgBus(c+81,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem13_new),32);
	vcdp->chgBus(c+82,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem14_new),32);
	vcdp->chgBus(c+83,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem15_new),32);
	vcdp->chgBit(c+84,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_we));
	vcdp->chgBus(c+85,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_new),6);
	vcdp->chgBit(c+86,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_we));
	vcdp->chgBus(c+87,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_new),32);
	vcdp->chgBus(c+88,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_0),32);
	vcdp->chgBus(c+89,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_1),32);
	vcdp->chgBus(c+90,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_9),32);
	vcdp->chgBus(c+91,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__w_14),32);
	vcdp->chgBus(c+92,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__d0),32);
	vcdp->chgBus(c+93,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem_update_logic__DOT__d1),32);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+94,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg_wren));
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+95,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__init_reg));
	vcdp->chgBit(c+96,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__next_reg));
	vcdp->chgBit(c+97,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__mode_reg));
	vcdp->chgBus(c+98,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[0]),32);
	vcdp->chgBus(c+99,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[1]),32);
	vcdp->chgBus(c+100,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[2]),32);
	vcdp->chgBus(c+101,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[3]),32);
	vcdp->chgBus(c+102,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[4]),32);
	vcdp->chgBus(c+103,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[5]),32);
	vcdp->chgBus(c+104,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[6]),32);
	vcdp->chgBus(c+105,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[7]),32);
	vcdp->chgBus(c+106,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[8]),32);
	vcdp->chgBus(c+107,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[9]),32);
	vcdp->chgBus(c+108,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[10]),32);
	vcdp->chgBus(c+109,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[11]),32);
	vcdp->chgBus(c+110,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[12]),32);
	vcdp->chgBus(c+111,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[13]),32);
	vcdp->chgBus(c+112,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[14]),32);
	vcdp->chgBus(c+113,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__block_reg[15]),32);
	vcdp->chgArray(c+114,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__digest_reg),256);
	vcdp->chgBus(c+122,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_awaddr),32);
	vcdp->chgBit(c+123,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_awready));
	vcdp->chgBit(c+124,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_wready));
	vcdp->chgBus(c+125,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_bresp),2);
	vcdp->chgBit(c+126,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_bvalid));
	vcdp->chgBus(c+127,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_araddr),32);
	vcdp->chgBit(c+128,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_arready));
	vcdp->chgBus(c+129,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_rdata),32);
	vcdp->chgBus(c+130,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_rresp),2);
	vcdp->chgBit(c+131,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_rvalid));
	vcdp->chgBus(c+132,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg0),32);
	vcdp->chgBus(c+133,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg1),32);
	vcdp->chgBus(c+134,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg2),32);
	vcdp->chgBus(c+135,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg3),32);
	vcdp->chgBus(c+136,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg4),32);
	vcdp->chgBus(c+137,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg5),32);
	vcdp->chgBus(c+138,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg6),32);
	vcdp->chgBus(c+139,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg7),32);
	vcdp->chgBus(c+140,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg8),32);
	vcdp->chgBus(c+141,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg9),32);
	vcdp->chgBus(c+142,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg10),32);
	vcdp->chgBus(c+143,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg11),32);
	vcdp->chgBus(c+144,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg12),32);
	vcdp->chgBus(c+145,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg13),32);
	vcdp->chgBus(c+146,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg14),32);
	vcdp->chgBus(c+147,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg15),32);
	vcdp->chgBus(c+148,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg16),32);
	vcdp->chgBus(c+149,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg17),32);
	vcdp->chgBus(c+150,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg18),32);
	vcdp->chgBus(c+151,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg19),32);
	vcdp->chgBus(c+152,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg20),32);
	vcdp->chgBus(c+153,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg21),32);
	vcdp->chgBus(c+154,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg22),32);
	vcdp->chgBus(c+155,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg23),32);
	vcdp->chgBus(c+156,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg24),32);
	vcdp->chgBus(c+157,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg25),32);
	vcdp->chgBus(c+158,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg26),32);
	vcdp->chgBus(c+159,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg27),32);
	vcdp->chgBus(c+160,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg28),32);
	vcdp->chgBus(c+161,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg29),32);
	vcdp->chgBus(c+162,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg30),32);
	vcdp->chgBus(c+163,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg31),32);
	vcdp->chgBus(c+164,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg32),32);
	vcdp->chgBus(c+165,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg33),32);
	vcdp->chgBus(c+166,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg34),32);
	vcdp->chgBus(c+167,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg35),32);
	vcdp->chgBus(c+168,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg36),32);
	vcdp->chgBus(c+169,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__slv_reg37),32);
	vcdp->chgBus(c+170,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__byte_index),32);
	vcdp->chgBit(c+171,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__aw_en));
	vcdp->chgBus(c+172,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__write_mem__DOT__i),32);
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+173,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__digest_valid_reg));
	vcdp->chgBus(c+174,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__a_reg),32);
	vcdp->chgBus(c+175,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__b_reg),32);
	vcdp->chgBus(c+176,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__c_reg),32);
	vcdp->chgBus(c+177,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__d_reg),32);
	vcdp->chgBus(c+178,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__e_reg),32);
	vcdp->chgBus(c+179,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__f_reg),32);
	vcdp->chgBus(c+180,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__g_reg),32);
	vcdp->chgBus(c+181,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__h_reg),32);
	vcdp->chgBus(c+182,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H0_reg),32);
	vcdp->chgBus(c+183,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H1_reg),32);
	vcdp->chgBus(c+184,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H2_reg),32);
	vcdp->chgBus(c+185,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H3_reg),32);
	vcdp->chgBus(c+186,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H4_reg),32);
	vcdp->chgBus(c+187,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H5_reg),32);
	vcdp->chgBus(c+188,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H6_reg),32);
	vcdp->chgBus(c+189,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__H7_reg),32);
	vcdp->chgBus(c+190,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__t_ctr_reg),6);
	vcdp->chgBus(c+191,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__sha256_ctrl_reg),2);
	vcdp->chgBus(c+192,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[0]),32);
	vcdp->chgBus(c+193,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[1]),32);
	vcdp->chgBus(c+194,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[2]),32);
	vcdp->chgBus(c+195,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[3]),32);
	vcdp->chgBus(c+196,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[4]),32);
	vcdp->chgBus(c+197,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[5]),32);
	vcdp->chgBus(c+198,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[6]),32);
	vcdp->chgBus(c+199,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[7]),32);
	vcdp->chgBus(c+200,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[8]),32);
	vcdp->chgBus(c+201,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[9]),32);
	vcdp->chgBus(c+202,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[10]),32);
	vcdp->chgBus(c+203,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[11]),32);
	vcdp->chgBus(c+204,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[12]),32);
	vcdp->chgBus(c+205,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[13]),32);
	vcdp->chgBus(c+206,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[14]),32);
	vcdp->chgBus(c+207,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_mem[15]),32);
	vcdp->chgBus(c+208,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__w_ctr_reg),6);
	vcdp->chgBus(c+209,(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__core__DOT__w_mem_inst__DOT__reg_update__DOT__i),32);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+210,(vlTOPp->clk_i));
	vcdp->chgBit(c+211,(vlTOPp->rst_ni));
	vcdp->chgBus(c+212,(vlTOPp->write_addr),32);
	vcdp->chgBus(c+213,(vlTOPp->write_prot),3);
	vcdp->chgBit(c+214,(vlTOPp->write_addr_valid));
	vcdp->chgBit(c+215,(vlTOPp->write_addr_ready));
	vcdp->chgBus(c+216,(vlTOPp->write_data),32);
	vcdp->chgBus(c+217,(vlTOPp->write_strb),4);
	vcdp->chgBit(c+218,(vlTOPp->write_data_valid));
	vcdp->chgBit(c+219,(vlTOPp->write_data_ready));
	vcdp->chgBit(c+220,(vlTOPp->write_resp_ready));
	vcdp->chgBus(c+221,(vlTOPp->write_resp),2);
	vcdp->chgBit(c+222,(vlTOPp->write_resp_valid));
	vcdp->chgBus(c+223,(vlTOPp->read_addr),32);
	vcdp->chgBus(c+224,(vlTOPp->read_prot),3);
	vcdp->chgBit(c+225,(vlTOPp->read_addr_valid));
	vcdp->chgBit(c+226,(vlTOPp->read_addr_ready));
	vcdp->chgBit(c+227,(vlTOPp->read_data_ready));
	vcdp->chgBus(c+228,(vlTOPp->read_data),32);
	vcdp->chgBus(c+229,(vlTOPp->read_resp),2);
	vcdp->chgBit(c+230,(vlTOPp->read_data_valid));
	vcdp->chgBit(c+231,((((IData)(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_arready) 
			      & (IData)(vlTOPp->read_addr_valid)) 
			     & (~ (IData)(vlTOPp->top__DOT__sha256_v1_0__DOT__sha256_v1_0_S00_AXI_inst__DOT__axi_rvalid)))));
    }
}
