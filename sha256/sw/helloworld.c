/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
// #include "platform.h"
// #include "xil_printf.h"

#include "sha256.h"

//    uint32_t block[16] = {0x61626380, 0x00000000, 0x00000000, 0x00000000,
//      0x00000000, 0x00000000, 0x00000000, 0x00000000,
//      0x00000000, 0x00000000, 0x00000000, 0x00000000,
//      0x00000000, 0x00000000, 0x00000000, 0x00000018};
//
//    char name[25] = {0};
//
//    unsigned int name0 = sha256_reg[ADDR_NAME0];
//
//    memcpy(&name[0], &sha256_reg[ADDR_NAME0], 4);
//    memcpy(&name[4], &sha256_reg[ADDR_NAME1], 4);
//    memcpy(&name[12],&sha256_reg[ADDR_VERSION], 4);
//
//    write_block(block);
//
//    sha256_reg[ADDR_CTRL] = (CTRL_MODE_VALUE + CTRL_INIT_VALUE);
//    sha256_reg[ADDR_CTRL] = (CTRL_MODE_VALUE);
//
//    unsigned int ctrl = sha256_reg[ADDR_CTRL];
//
//    wait_ready();
//
//    uint32_t data_digest[8];

//    read_digest(data_digest);

#define TEST_MAX 4

size_t
my_strlen(str)
	const char *str;
{
	register const char *s;

	for (s = str; *s; ++s);
	return(s - str);
}

void _exit() {
  // while(1) {
  //   asm("nop");
  // }
  return;
}

int main()
{
//    unsigned char buf[32] = {0};
    unsigned int buf[8] = {0};

    const unsigned char* test[TEST_MAX] = {
			(const unsigned char*)"abc",
			(const unsigned char*)"",
			(const unsigned char*)"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
	 		(const unsigned char*)"abcdefghbcdefghicdefghijdefghijkefghijklfghijklmghijklmnhijklmnoijklmnopjklmnopqklmnopqrlmnopqrsmnopqrstnopqrstu",
    };

    unsigned int test_oracle[TEST_MAX][8] = {
			{0xba7816bf, 0x8f01cfea, 0x414140de, 0x5dae2223, 0xb00361a3, 0x96177a9c, 0xb410ff61, 0xf20015ad},
			{0xe3b0c442, 0x98fc1c14, 0x9afbf4c8, 0x996fb924, 0x27ae41e4, 0x649b934c, 0xa495991b, 0x7852b855},
			{0x248d6a61, 0xd20638b8, 0xe5c02693, 0x0c3e6039, 0xa33ce459, 0x64ff2167, 0xf6ecedd4, 0x19db06c1},
    		{0xcf5b16a7, 0x78af8380, 0x036ce59e, 0x7b049237, 0x0b249b11, 0xe8f07a51, 0xafac4503, 0x7afee9d1}
    };

    // for(int i=0; i<1; i++) {
    // 	sha256_hash(buf, test[i], my_strlen((const char*)test[i]));
		//
    // 	if(memcmp(buf, test_oracle[i], 32) != 0) {
    // 		//error case
    // 		while(1);
    // 	}
    // }

		sha256_hash(buf, test[0], my_strlen((const char*)test[0]));

    return 0;
}
