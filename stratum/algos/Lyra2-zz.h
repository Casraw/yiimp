/**
 * Header file for the Lyra2 Password Hashing Scheme (PHS).
 *
 * Author: The Lyra PHC team (http://www.lyra-kdf.net/) -- 2014.
 *
 * This software is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef LYRA2ZZ_H_
#define LYRA2ZZ_H_

#include <stdint.h>

typedef unsigned char byte;

//Block length required so Blake2's Initialization Vector (IV) is not overwritten (THIS SHOULD NOT BE MODIFIED)
#define BLOCK_LEN_BLAKE2_SAFE_INT64 8                                   //768 bits (=96 bytes, =12 uint64_t)
#define BLOCK_LEN_BLAKE2_SAFE_BYTES (BLOCK_LEN_BLAKE2_SAFE_INT64 * 8)   //same as above, in bytes

#define LYRA2ZZ_BLOCK_HEADER_LEN_BYTES 112
#define LYRA2ZZ_BLOCK_HEADER_NONCE_OFFSET 19 /* 19 * 4 bytes */

#define LYRA2ZZ_BLOCK_HEADER_UINT32_LEN 32

#ifdef BLOCK_LEN_BITS
        #define BLOCK_LEN_INT64 (BLOCK_LEN_BITS/64)      //Block length: 1024 bits (=128 bytes, =16 uint64_t)
        #define BLOCK_LEN_BYTES (BLOCK_LEN_BITS/8)       //Block length, in bytes
#else   //default block length: 1024 bits
        #define BLOCK_LEN_INT64 12                       //Block length: 1024 bits (=128 bytes, =16 uint64_t)
        #define BLOCK_LEN_BYTES (BLOCK_LEN_INT64 * 8)    //Block length, in bytes
#endif

#ifdef __cplusplus
extern "C" {
#endif

    int LYRA2ZZ(void *K, uint64_t kLen, const void *pwd, uint64_t pwdlen, const void *salt, uint64_t saltlen, uint64_t timeCost, uint64_t nRows, uint64_t nCols);

#ifdef __cplusplus
}

#endif

#endif /* LYRA2_H_ */
