
CC=gcc -g -ggdb

#CFLAGS=-c -g -I /usr/include/mysql
#LDFLAGS=-g

CXXFLAGS = -O2 -I.. -march=native
CFLAGS= $(CXXFLAGS) -std=gnu99
LDFLAGS=-O2 -lgmp

SOURCES=x17.c heavyhash/keccak_tiny.c heavyhash/heavyhash.c curvehash.c bastion.c skein2.c \
cryptonote/cryptonight_lite.c cryptonote/cryptonight_dark.c cryptonote/crypto/c_skein.c cryptonote/crypto/c_jh.c cryptonote/crypto/c_blake256.c cryptonote/crypto/hash.c \
cryptonote/crypto/c_groestl.c cryptonote/crypto/c_keccak.c cryptonote/crypto/oaes_lib.c cryptonote/crypto/aesb.c cryptonote/cryptonight_soft_shell.c cryptonote/cryptonight_dark_lite.c \
cryptonote/cryptonight_turtle.c cryptonote/cryptonight_turtle_lite.c cryptonote/cryptonight_fast.c cryptonote/cryptonight.c sha256csm.c Lyra2-z.c \
x22.c scrypt.c skydoge.c gltalgos.c sha256.c lbk3.c \
0x10.c Lyra2.c allium.c velvet.c rainforest.c anime.c \
a5amath.c x11kvs.c KeccakP-800-reference.c x16rv2.c mike.c lyra2zz.c \
vitalium.c Sponge.c pentablake.c blake.c hsr14.c x21s.c \
sib.c x14.c aergo.c argon2a.c quark.c dedal.c \
yescrypt.c x16s.c x17r.c minotaur.c x11.c luffa.c \
scryptn.c renesis.c xevan.c qubit.c tribus.c a5a.c \
hmq17.c c11.c lane.c SWIFFTX/SWIFFTX.c blake2s.c veltor.c \
lyra2v2.c geek.c phi1612.c sha256_Y.c sha256t.c lyra2v3.c \
lbry.c jha.c megabtx.c Lyra2-zz.c keccak.c sha256dt.c \
whirlpool.c blake2b.c skein.c lyra2re.c honeycomb/facet_one.c \
honeycomb/facet_six.c honeycomb/facet_four.c honeycomb/facet_five.c honeycomb/facets_helper.c honeycomb/facet_three.c honeycomb/facet_two.c \
beenode.c blake2-ref/blake2s.c blake2-ref/blake2b.c sha256q.c phi.c \
x20r.c balloon.c sha3d.c x11k.c lyra2z.c x15.c \
x11evo.c sm3.c drop.c argon2d/argon2.c argon2d/opt.c argon2d/thread.c \
argon2d/encoding.c argon2d/core.c lyra2z330.c deep.c hive.c \
blake2/blake2b.c groestl.c yescrypt-platform.c memehash.c megamec.c blakecoin.c \
yespower/yespower-combined.c yespower/crypto/blake2b-yp.c yespower/yespower-platform.c yespower/yespower-blake2b.c bmw.c x18.c \
sha256-d.c fresh.c x16rt.c qureno.c neoscrypt.c x25x.c \
sonoa.c bitcore.c bmw512.c polytimos.c argon2m.c hex.c \
ar2/argon2.c ar2/cores.c ar2/ar2-scrypt-jane.c ar2/blake2b.c ar2/opt.c \
ar2/thread.c ar2/ref.c \
nist5.c cosa.c x13.c timetravel.c bcd.c pipehash.c \
minotaurx.c m7m.c yescrypt-opt.c sha256-P.c gost.c zr5.c \
x12.c exosis.c lyra2re3.c phi2.c gr.c pomelo.c \
x16r.c sha512_256.c phi5.c skunk.c lyra2vc0ban.c whirlpoolx.c \
x22i.c
	
OBJECTS=$(SOURCES:%.c=%.o) $(SOURCES:%.cpp=%.o) $(SOURCES:%.cc=%.o)
OUTPUT=libalgos.a

all: $(SOURCES) $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	ar rc $@ $(OBJECTS)
	touch ../stratum.cpp

.cpp.o:
	$(CC) $(CXXFLAGS) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

#	$(CC) $(CFLAGS) -std=gnu99 -Wno-pointer-sign -Wno-pointer-to-int-cast -funroll-loops -fvariable-expansion-in-unroller -fmerge-all-constants -fbranch-target-load-optimize2 -fsched2-use-superblocks -falign-loops=16 -falign-functions=16 -falign-jumps=16 -falign-labels=16 -Ofast -flto -fuse-linker-plugin -ftree-loop-if-convert-stores -DUSE_ASM -pg $<

clean:
	rm -f *.o
	rm -f ar2/*.o
	rm -f blake2/*.o	
	rm -f blake2-ref/*.o	
	rm -f cryptonote/*.o	
	rm -f heavyhash/*.o	
	rm -f honeycomb/*.o	
	rm -f SWIFFTX/*.o	
	rm -f yespower/*.o	
