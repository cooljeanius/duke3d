ACLOCAL_AMFLAGS = -I m4 --install

#-----------------------------------------------------------------------------#
# Duke3D makefile.
#-----------------------------------------------------------------------------#

linux_ppc := false
beos := false
if BUILDING_FOR_APPLE_HOST
macosx := true
else
macosx := false
endif
freebsd := false
solaris := false
shareware := false
controls_menu := true

#-----------------------------------------------------------------------------#
# If this makefile fails to detect Cygwin correctly, or you want to force
#  the build process's behaviour, set it to "true" or "false" (w/o quotes).
#-----------------------------------------------------------------------------#
cygwin := autodetect

# you only need to set these for Cygwin at the moment.
SDL_INC_DIR = /cygdrive/c/SDL/include
SDL_LIB_DIR = /cygdrive/c/SDL/lib

CC = @CC@

# need this for now.
@ifGNUmake@ifeq ($(strip $(beos)),true)
@ifGNUmake@  use_asm := false
@ifGNUmake@endif

# Don't touch anything below this line unless you know what you're doing.

@ifGNUmake@ifeq ($(strip $(cygwin)),autodetect)
@ifGNUmake@  ifneq ($(strip $(shell gcc -v 2>&1 |grep "cygwin")),)
@ifGNUmake@    cygwin := true
@ifGNUmake@  else
@ifGNUmake@    cygwin := false
@ifGNUmake@  endif
@ifGNUmake@endif


@ifGNUmake@ifeq ($(strip $(cygwin)),true)
@ifGNUmake@  ifeq ($(strip $(SDL_INC_DIR)),please_set_me_cygwin_users)
@ifGNUmake@    $(error Cygwin users need to set the SDL_INC_DIR envr var.)
@ifGNUmake@  else
@ifGNUmake@    SDL_CFLAGS := -I$(SDL_INC_DIR)
@ifGNUmake@  endif
@ifGNUmake@
@ifGNUmake@  ifeq ($(strip $(SDL_LIB_DIR)),please_set_me_cygwin_users)
@ifGNUmake@    $(error Cygwin users need to set the SDL_LIB_DIR envr var.)
@ifGNUmake@  else
@ifGNUmake@    SDL_LDFLAGS := -L$(SDL_LIB_DIR) -lSDL
@ifGNUmake@  endif
@ifGNUmake@
@ifGNUmake@else
@ifGNUmake@  ifneq ($(strip $(freebsd)),true)
@ifGNUmake@    SDL_CFLAGS := $(shell sdl-config --cflags)
@ifGNUmake@    SDL_LDFLAGS := $(shell sdl-config --libs) -L.
@ifGNUmake@  endif
@ifGNUmake@endif

@ifGNUmake@ifeq ($(strip $(macosx)),true)
@ifGNUmake@  EXTRACFLAGS += -DPLATFORM_MACOSX=1
@ifGNUmake@  EXTRALDFLAGS += -lSDLmain
@ifGNUmake@endif

@ifGNUmake@ifeq ($(strip $(freebsd)),true)
@ifGNUmake@  EXTRACFLAGS += -DPLATFORM_FREEBSD=1
@ifGNUmake@  SDL_CFLAGS := $(shell sdl11-config --cflags)
@ifGNUmake@  SDL_LDFLAGS := $(shell sdl11-config --libs) -L.
@ifGNUmake@endif

@ifGNUmake@ifeq ($(strip $(linux_ppc)),true)
@ifGNUmake@  EXTRACFLAGS += -DPLATFORM_LINUXPPC=1
@ifGNUmake@endif

@ifGNUmake@ifneq ($(strip $(cygwin)),true)
@ifGNUmake@  ifneq ($(strip $(macosx)),true)
@ifGNUmake@    ifneq ($(strip $(beos)),true)
@ifGNUmake@      EXTRACFLAGS += -DUSE_EXECINFO=1
@ifGNUmake@    endif
@ifGNUmake@  endif
@ifGNUmake@endif

@ifGNUmake@ifeq ($(strip $(solaris)),true)
@ifGNUmake@  CC = cc
@ifGNUmake@  EXTRALDFLAGS += -lsocket -lnsl
@ifGNUmake@  CFLAGS += -DPLATFORM_SOLARIS
@ifGNUmake@endif

@ifGNUmake@ifeq ($(strip $(shareware)),true)
@ifGNUmake@  EXTRACFLAGS += -DVOLUMEONE
@ifGNUmake@else
@ifGNUmake@  EXTRACFLAGS += -DVOLUMEALL
@ifGNUmake@endif

@ifGNUmake@ifeq ($(strip $(controls_menu)),true)
@ifGNUmake@  EXTRACFLAGS += -DCONTROLS_CONFIG_MENU=1
@ifGNUmake@endif

BUILDOBJS := \
	buildengine/cache1d.o \
	buildengine/engine.o \
	buildengine/sdl_driver.o \
	buildengine/mmulti.o \
	buildengine/pragmas.o \
	buildengine/unix_compat.o

@ifGNUmake@ifeq ($(strip $(use_asm)),true)
@ifGNUmake@	BUILDOBJS += buildengine/a_gnu.o buildengine/a_nasm.o
@ifGNUmake@else
@ifGNUmake@	BUILDOBJS += buildengine/a.o
@ifGNUmake@endif

CFLAGS = -c -g $(SDL_CFLAGS) -DUSE_SDL=1 -DPLATFORM_UNIX=1 $(EXTRACFLAGS)

@ifGNUmake@ifeq ($(strip $(solaris)),true)
@ifGNUmake@	CFLAGS += -xO5 -xchar=u
@ifGNUmake@else
@ifGNUmake@	# Always turn OFF strict aliasing, even when optimizing.
@ifGNUmake@     # Otherwise, this is just an accident waiting to happen. -ryan
@ifGNUmake@	CFLAGS += -fno-strict-aliasing
@ifGNUmake@	CFLAGS += -W -Wall -Wno-unused -funsigned-char
@ifGNUmake@	ifeq ($(strip $(macosx)),true)
@ifGNUmake@		OPTIMIZE = -O3 -mdynamic-no-pic -falign-loops=16
@ifGNUmake@	else
@ifGNUmake@		OPTIMIZE = -O2
@ifGNUmake@	endif
@ifGNUmake@endif

# Rename these to compile with the Intel compiler (v6.0)
INTEL_CC = icc
INTEL_CFLAGS = -g $(SDL_CFLAGS) -DUSE_SDL=1 -DPLATFORM_UNIX=1 -DUSE_I386_ASM=1 $(EXTRACFLAGS) -O2

LDLIBS = $(SDL_LDFLAGS) -lSDL -lSDL_mixer $(EXTRALDFLAGS)

@ifGNUmake@ifeq ($(strip $(freebsd)),true)
@ifGNUmake@LDLIBS = $(SDL_LDFLAGS) -lSDL_mixer $(EXTRALDFLAGS)
@ifGNUmake@endif

# !!! FIXME: Do we even need this? It doesn't fly on MacOS X.  --ryan.
BROKEN_LDLIBS = -Wl,-E

.PHONY: duke3d build buildengine clean distclean
all: buildengine duke3d build


%.o : %.c
	$(CC) $(CFLAGS) $(OPTIMIZE) -o $@ $< $(CPPFLAGS)

# Animation playback crashes due to optimization error on MacOS X. --ryan.
@ifGNUmake@ifeq ($(strip $(macosx)),true)
@ifGNUmake@animlib.o : animlib.c
@ifGNUmake@	$(CC) $(CFLAGS) -o $@ $<
@ifGNUmake@endif

# Animation playback crashes due to optimization error on Linux PPC. --Felipe Barriga.
@ifGNUmake@ifeq ($(strip $(linux_ppc)),true)
@ifGNUmake@animlib.o : animlib.c
@ifGNUmake@	$(CC) $(CFLAGS) -o $@ $<
@ifGNUmake@endif

audiolib/audiolib.a:
	$(MAKE) -C audiolib -f Makefile_orig \
	  CC="$(CC)" CFLAGS="$(CFLAGS)" LDLIBS="$(LDLIBS)" \
	  CPPFLAGS="$(CPPFLAGS)"

buildengine:
	make -C buildengine -f Makefile_orig

duke3d: \
	actors.o \
	animlib.o \
	control.o \
	config.o \
	game.o \
	gamedef.o \
	global.o \
	keyboard.o \
	menues.o \
	player.o \
	premap.o \
	rts.o \
	scriplib.o \
	sector.o \
	sounds.o \
	dukemusc.o \
	audiolib/audiolib.a
	$(CC) $^ $(BUILDOBJS) $(LDLIBS) -o $@

build: astub.o
	$(CC) $^ $(BUILDOBJS) buildengine/build.o $(LDLIBS) -o $@

clean-local:
	$(MAKE) -C audiolib -f Makefile_orig clean
	$(MAKE) -C buildengine -f Makefile_orig clean
	rm -rf duke3d build *.o

distclean-local: clean-local
	if test -e audiolib/Makefile_orig; then \
	  $(MAKE) -C audiolib -f Makefile_orig distclean; \
	elif test -e audiolib/Makefile; then \
	  $(MAKE) -C audiolib -f Makefile distclean; \
	fi
	if test -e buildengine/Makefile_orig; then \
	  $(MAKE) -C buildengine -f Makefile_orig distclean; \
	elif test -e buildengine/Makefile; then \
	  $(MAKE) -C buildengine -f Makefile distclean; \
	fi
	rm -rfv autom4te.cache || rmdir autom4te.cache
	rm -rfv *~ build-aux/*~ m4/*~ autoscan.log
