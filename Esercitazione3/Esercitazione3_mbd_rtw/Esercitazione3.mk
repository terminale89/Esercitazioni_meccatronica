#
# File    : mbd_s32k.tmf
#
# Abstract:
#       Template makefile used to create <model>.mkfile for target.
#
#       This makefile attempts to conform to the guidelines specified in the
#       IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make (gmake) which is located in matlabroot/bin/win64.
#
#       Note that this template is automatically customized by the build
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPT_OPTS       - Optimization options. efault is none. To enable
#                          debugging specify as OPT_OPTS=-g4.
#         OPTS           - User specific compile options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#                          (For Lcc, have a '/'as file seperator before the
#                          file name instead of a '\' .
#                          i.e.,  d:\work\proj1/myfile.c - reqd for 'gmake')
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc
#
# Copyright (c) 2017-2022 NXP.
# All rights reserved.
#


#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = "%MATLAB%\bin\win64\gmake"
SHELL           = cmd
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = any
COMPILER_TOOL_CHAIN = default
BUILD_SUCCESS	= *** Created executable:


#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS         - List of additional S-function modules.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  PORTABLE_WORDSIZES  - Is this build intented for SIL simulation with portable word sizes (1/0)?
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules
#                            and do not build an executable

MODEL                = Esercitazione3
MODULES              = mbd_main.c clock_S32K1xx.c interrupt_manager.c lpit_driver.c pins_driver.c pins_port_hw_access.c power_manager.c power_manager_S32K1xx.c power_smc_hw_access.c s32k_clock_init.c startup.c system_S32K142.c
MAKEFILE             = Esercitazione3.mk
MATLAB_ROOT          = C:\Program Files\MATLAB\R2022b
ALT_MATLAB_ROOT      = C:\PROGRA~1\MATLAB\R2022b
START_DIR            = C:\universita\Meccatronica\Esercitazioni_meccatronica\Esercitazione3
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = 
SOLVER               = 
NUMST                = 1
TID01EQ              = 0
NCSTATES             = 0
MEM_ALLOC            = RT_STATIC
COMPUTER             = PCWIN64
BUILDARGS            = COPY_MDLREF_INCLUDES=0 GENERATE_ERT_S_FUNCTION=0 INCLUDE_MDL_TERMINATE_FCN=1 COMBINE_OUTPUT_UPDATE_FCNS=1 MULTI_INSTANCE_CODE=0 INTEGER_CODE=0 OPTS="-DTID01EQ=0"
MULTITASKING         = 0
MAT_FILE             = 0
GENERATE_ASAP2 	     = 0
EXT_MODE             = 0
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000

MAKEFILEBUILDER_TGT = 0
STANDALONE_SUPPRESS_EXE = 0
GEN_SAMPLE_MAIN = 0

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
SHARED_LIB_LINK      = $(subst /,\,$(SHARED_LIB))
LIB_SKIP             = rt_logging.o avi_rt.o

#---------------------- User defined tokens ------------------------------------

TARGET_MCU              = S32K142
SDK_TARGET_MCU          = S32K142
TARGET_COMPILER         = GCC
TARGET_MEMORY           = START_FROM_FLASH
FPU_USED                = 1
LINKER_FILE_NAME        = S32K14x.ld
MC_LIB_NAME             = S32K14x_AMMCLIB.a
COPY_DEST_DIR           = 
TBX_SRCS                = 

#--------------------------- GCC -----------------------
GCC_TARGET_CC_OPTS      = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O1 -g -gstrict-dwarf -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
GCC_TARGET_ASM_OPTS     = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -g -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
GCC_TARGET_LINK_OPTS    = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
GCC_TARGET_LIB_OPTS     = 
#--------------------------- GHS -----------------------
GHS_TARGET_CC_OPTS      = -cpu=cortexm4f -thumb -fpu=vfpv4_d16 -fsingle -Ogeneral -Wundef -Wimplicit-int -Wshadow -Wtrigraphs --no_commons --gnu_asm -gnu99 -gdwarf-2 -G  -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
GHS_TARGET_ASM_OPTS     = -cpu=cortexm4f -fpu=vfpv4_d16 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
GHS_TARGET_LINK_OPTS    = -cpu=cortexm4f -thumb -fpu=vfpv4_d16 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
GHS_TARGET_LIB_OPTS     = 
#--------------------------- IAR -----------------------
IAR_TARGET_CC_OPTS      =  --thumb  -Ol -e --debug --dlib_config normal -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
IAR_TARGET_ASM_OPTS     =  --thumb  -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
IAR_TARGET_LINK_OPTS    = --no_exceptions --vfe --inline -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard
IAR_TARGET_LIB_OPTS     = 

#----------Parse TARGET_MCU and get only the processor family -----------------

include_opt = I
define_opt = D

#--------------------------- Model and reference models -----------------------
MODELLIB                  = 
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE      = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
  MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
  MATLAB_BIN := $(ALT_MATLAB_BIN)
endif

#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -DWIN32 # -DVERBOSE
  ifeq ($(EXTMODE_TRANSPORT),0) #serial_win32
    EXT_SRC  = ext_svr.c updown.c ext_work.c ext_svr_serial_transport.c
    EXT_SRC += ext_serial_pkt.c rtiostream_serial_interface.c rtiostream_serial.c
    EXT_CC_OPTS += -DEXTMODE_DISABLE_ARGS_PROCESSING -DEXTMODE_DISABLEPRINTF
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC     += mem_mgr.c
    EXT_CC_OPTS += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif

#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-$(include_opt)"$(MATLAB)\simulink\include" \
	-$(include_opt)"$(MATLAB)\extern\include" \
	-$(include_opt)"$(MATLAB)\rtw\c\src" \
	-$(include_opt)"$(MATLAB)\rtw\c\libsrc" \
	-$(include_opt)"$(MATLAB)\rtw\c\src\ext_mode\common" \
	-$(include_opt)"$(MATLAB)\rtw\c\src\ext_mode\tcpip" \
	-$(include_opt)"$(MATLAB)\rtw\c\src\ext_mode\serial" \
	-$(include_opt)"$(MATLAB)\rtw\c\src\ext_mode\custom"

# Additional includes
ADD_INCLUDES = \
	-$(include_opt)$(START_DIR) \
	-$(include_opt)$(START_DIR)\Esercitazione3_mbd_rtw \
	-$(include_opt)$(MATLAB_ROOT)\extern\include \
	-$(include_opt)$(MATLAB_ROOT)\simulink\include \
	-$(include_opt)$(MATLAB_ROOT)\rtw\c\src \
	-$(include_opt)$(MATLAB_ROOT)\rtw\c\src\ext_mode\common \
	-$(include_opt)$(MATLAB_ROOT)\rtw\c\ert \


SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -$(include_opt)$(SHARED_SRC_DIR)
endif

#------------------------------ Libraries -----------------------------------

LIBS =
 
 

LIBS =
 
 

LIBS += $(S_FUNCTIONS_LIB)

#---------------------------------TOOLCHAIN------------------------------------
#----------------- Define tools to build using command line -------------------
#------------------------------------------------------------------------------

#================== GCC ========================
ifeq ($(TARGET_COMPILER), GCC)
  TOOL_ROOT=$(GCC_S32K_TOOL)
  CMDLINE_TOOLS=$(TOOL_ROOT)/bin

  CC="$(CMDLINE_TOOLS)/arm-none-eabi-gcc"
  AS="$(CMDLINE_TOOLS)/arm-none-eabi-gcc"
  LD="$(CMDLINE_TOOLS)/arm-none-eabi-gcc"
  LIBCMD="$(CMDLINE_TOOLS)/arm-none-eabi-ar"
  ELF_TOOL="$(CMDLINE_TOOLS)/arm-none-eabi-objcopy"
  SIZE_TOOL="$(CMDLINE_TOOLS)/arm-none-eabi-size"

  TOOL_INCLUDES +=-$(include_opt)"$(TOOL_ROOT)/arm-none-eabi/include"
  TOOL_LIB += -specs=nosys.specs --sysroot="$(TOOL_ROOT)/arm-none-eabi/newlib" -lm

  CC_OPTS=-c $(GCC_TARGET_CC_OPTS) -$(define_opt)__FPU_PRESENT=$(FPU_USED) -$(define_opt)$(TARGET_MEMORY) \
    -$(define_opt)__FPU_USED=$(FPU_USED) -$(define_opt)__NVIC_PRIO_BITS=FEATURE_NVIC_PRIO_BITS -$(define_opt)ERRATA_E9527 -o $@
  AS_OPTS=-c $(GCC_TARGET_ASM_OPTS) -x assembler-with-cpp -$(define_opt)$(TARGET_MEMORY) -o $@
  LD_OPTS=$(GCC_TARGET_LINK_OPTS) -Xlinker --gc-sections -Xlinker --defsym=__ram_vector_table__=1
endif

#================== GHS ========================
ifeq ($(TARGET_COMPILER), GreenHills Multi)
  TOOL_ROOT=$(GHS_S32K_TOOL)
  CMDLINE_TOOLS=$(TOOL_ROOT)

  CC="$(CMDLINE_TOOLS)/ccarm"
  AS="$(CMDLINE_TOOLS)/ccarm"
  LD="$(CMDLINE_TOOLS)/elxr"
  LIBCMD="$(CMDLINE_TOOLS)/ccarm"
  ELF_TOOL="$(CMDLINE_TOOLS)/gdump"
  GSREC_TOOL="$(CMDLINE_TOOLS)/gsrec"

  CC_OPTS=-c $(GHS_TARGET_CC_OPTS) --diag_suppress=47 -preprocess_assembly_files -$(define_opt)asm=__asm__ \
    -$(define_opt)__FPU_PRESENT=$(FPU_USED) -$(define_opt)$(TARGET_MEMORY) \
    -$(define_opt)__FPU_USED=$(FPU_USED) -$(define_opt)__NVIC_PRIO_BITS=FEATURE_NVIC_PRIO_BITS -$(define_opt)ERRATA_E9527
  AS_OPTS=-c $(GHS_TARGET_ASM_OPTS) -preprocess_assembly_files -$(define_opt)$(TARGET_MEMORY)
  LD_OPTS=$(GHS_TARGET_LINK_OPTS)
  AR_OPTS = -archive $(CC_OPTS) $(GHS_TARGET_LIB_OPTS)

endif

#================== IAR ========================
ifeq ($(TARGET_COMPILER), IAR)
  TOOL_ROOT=$(IAR_TOOL)
  CMDLINE_TOOLS=$(TOOL_ROOT)

  CC="$(CMDLINE_TOOLS)/arm/bin/iccarm"
  AS="$(CMDLINE_TOOLS)/arm/bin/iasmarm"
  LD="$(CMDLINE_TOOLS)/arm/bin/ilinkarm"
  LIBCMD="$(CMDLINE_TOOLS)/arm/bin/iarchive"
  ELF_TOOL="$(CMDLINE_TOOLS)/arm/bin/ielftool"

  CC_OPTS=$(IAR_TARGET_CC_OPTS) -$(define_opt)__FPU_PRESENT=$(FPU_USED) -$(define_opt)$(TARGET_MEMORY) \
    -$(define_opt)__FPU_USED=$(FPU_USED) -$(define_opt)__NVIC_PRIO_BITS=FEATURE_NVIC_PRIO_BITS -$(define_opt)ERRATA_E9527 -o $@
  AS_OPTS=$(IAR_TARGET_ASM_OPTS) -$(define_opt)$(TARGET_MEMORY)
endif

#---------------------------------- SDK ---------------------------------------

CMSIS_INCLUDES  = \
    -$(include_opt)"./common" \
    -$(include_opt)"./inc" \
    -$(include_opt)"./src/clock/S32K1xx" \
    -$(include_opt)"./src/sim/$(TARGET_MCU)" \
    -$(include_opt)"./src/power/S32K1xx" \
    -$(include_opt)"./$(TARGET_MCU)/include" \
    -$(include_opt)"../common" \
    -$(include_opt)"../inc" \
    -$(include_opt)"../src/clock/S32K1xx" \
    -$(include_opt)"../src/sim/$(TARGET_MCU)" \
    -$(include_opt)"../src/power/S32K1xx" \
    -$(include_opt)"../$(TARGET_MCU)/include" \
    -$(include_opt)"../instrumented/common" \
    -$(include_opt)"../instrumented/inc" \
    -$(include_opt)"../instrumented/src/clock/S32K1xx" \
    -$(include_opt)"../instrumented/src/sim/$(TARGET_MCU)" \
    -$(include_opt)"../instrumented/src/power/S32K1xx" \
    -$(include_opt)"../instrumented/$(TARGET_MCU)/include"

CC_OPTS += -$(define_opt)CPU_$(SDK_TARGET_MCU)

#------------------------------------------------------------------------------

LIB_TEMP  = libs

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------

INCLUDES =  -$(include_opt). \
	-$(include_opt).. \
	-$(include_opt)../instrumented \
	-$(include_opt)$(RELATIVE_PATH_TO_ANCHOR) \
	$(MATLAB_INCLUDES) \
	$(ADD_INCLUDES) \
	$(TOOL_INCLUDES) \
	$(USER_INCLUDES) \
	$(MODELREF_INC_PATH) \
	$(SHARED_INCLUDES) \
	$(CMSIS_INCLUDES) \
    $(INSTRUMENT_INCLUDES)

#-------------------- Definitons for application files: -----------------------
#
# C_SRCS       = all application specific C source files.
# S_SRCS       = all application specific assembly source files.
# APP_INCS     = all application specific include files.
#
S_SRCS_LIST = startup_$(TARGET_MCU).s
LD_FILE = $(LINKER_FILE_NAME)
MC_LIB = $(MC_LIB_NAME)
# Generating append prefix
ifeq ("$(COPY_DEST_DIR)", "")
    INSTR_PREFIX = ..
else
    INSTR_PREFIX = ..\instrumented
endif

C_SRCS_LIST = $(S_FUNCTIONS)
ifeq ($(MODELREF_TARGET_TYPE), NONE)
  ifeq ($(MAKEFILEBUILDER_TGT),1)
    #----------- MODELREF_TARGET_TYPE = NONE  MAKEFILEBUILDER_TGT = 1
    # Top-level model for PIL RTW
    PRODUCT                  = $(MODEL).mot
    BUILD_PRODUCT_TYPE       = executable
    # We reuse the prebuilt objects from the PIL block or the referenced model.
    PREBUILT_OBJS           += $(MODULES:.c=.o)
    SKIP_MODELREF_LINK_LIBS  = .. ../instrumented
    MODELREF_LINK_LIBS      := $(filter-out $(SKIP_MODELREF_LINK_LIBS),$(MODELREF_LINK_LIBS))

    S_SRCS                  := $(addprefix $(INSTR_PREFIX)\, $(S_SRCS_LIST))
    MC_LIB                  := $(addprefix $(INSTR_PREFIX)\, $(MC_LIB))
    LD_FILE                 := $(addprefix $(INSTR_PREFIX)\, $(LD_FILE))    
  else
    ifeq ($(STANDALONE_SUPPRESS_EXE),1)
      #----------- MODELREF_TARGET_TYPE = NONE  MAKEFILEBUILDER_TGT = 0  STANDALONE_SUPPRESS_EXE = 1
      #--- Build library only for top level model
      # PIL block, Autosar PIL
      PRODUCT            = ObjectModulesOnly
      BUILD_PRODUCT_TYPE = object modules
      C_SRCS_LIST      += $(MODULES)  $(TBX_SRCS) $(MODEL).c $(EXT_SRC)
    else
      #----------- MODELREF_TARGET_TYPE = NONE  MAKEFILEBUILDER_TGT = 0  STANDALONE_SUPPRESS_EXE = 0
      #--- Stand-alone model (.exe) ---
      # Top-level model for Build RTW
      PRODUCT            = $(MODEL).mot
      BUILD_PRODUCT_TYPE = executable
      C_SRCS_LIST       += $(MODULES) $(TBX_SRCS) $(MODEL).c $(EXT_SRC)
      S_SRCS            := $(S_SRCS_LIST)
    endif
  endif
else
  #----------- MODELREF_TARGET_TYPE = RTW,SIM
  #--- Model reference coder target
  PRODUCT             = $(MODELLIB)
  BUILD_PRODUCT_TYPE  = library
  C_SRCS_LIST       += $(MODULES) $(TBX_SRCS)
  MC_LIB :=
endif

C_SRCS = $(sort $(C_SRCS_LIST))

CFLAGS = $(INCLUDES) \
	$(CFLAGS_MODE) \
	$(EXT_CC_OPTS) \
	$(OPTS)

ifneq ("$(MC_LIB_NAME)","")
  TOOL_LIB += $(MC_LIB)
endif
#
#------------------------ Construct the object file lists------------------------
#
C_OBJS = $(C_SRCS:.c=.o)
S_OBJS = $(S_SRCS:.s=.o)
OBJS = $(S_OBJS) $(C_OBJS)

SHARED_SRC := $(subst \,/,$(SHARED_SRC))
SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix .o, $(basename $(SHARED_SRC)))
#
#----------------------- make all variables available to sub-makes---------------
#
export

#
#---------------------------------------Build rules------------------------------
#

RM = @del /F
all : clean SetupFiles $(PRODUCT)
	@echo Building target $@
	@echo $(BUILD_SUCCESS) $(PRODUCT)

clean:
	@echo Cleaning...
	@echo RELATIVE_PATH_TO_ANCHOR is $(RELATIVE_PATH_TO_ANCHOR)
	@echo ==== Removing object files from build directory ====
	@if exist $(PRODUCT) del $(PRODUCT)
	@if exist *.o $(RM) *.o
	@if exist *.obj $(RM) *.obj
	@if exist *.elf $(RM) *.elf
	@if exist *.s19 $(RM) *.s19
	@if exist *.out $(RM) *.out
	@if exist *.mot $(RM) *.mot
	@if exist *.bin $(RM) *.bin
	@if exist *.srz $(RM) *.srz
	@if exist *.d   $(RM) *.d
	@if exist *.dbo $(RM) *.dbo
	@if exist *.rsp $(RM) *.rsp
	@if exist *.lst  $(RM) *.lst
	@if exist err.log $(RM) err.log
	@if exist *.dbo  $(RM) *.dbo
	@if exist *.dla  $(RM) *.dla
	@if exist *.dnm  $(RM) *.dnm
	@if exist *.dep  $(RM) *.dep
	@if exist *.inf  $(RM) *.inf


SetupFiles:
	@echo Compiler details : $(CC) $(CC_OPTS) $(CFLAGS)
	@echo Assembler details : $(AS) $(AS_OPTS)
	@echo Product: $(PRODUCT)
	@echo Build product type: $(BUILD_PRODUCT_TYPE)

$(MODEL).mot: $(MODEL).elf
	@echo Generating S-record...
    ifeq ($(TARGET_COMPILER), GCC)
	$(ELF_TOOL) -O srec $(MODEL).elf $(MODEL).mot
	$(SIZE_TOOL) --format=berkeley $(MODEL).elf
    endif
    ifeq ($(TARGET_COMPILER), IAR)
	$(ELF_TOOL) $(MODEL).elf $(MODEL).mot --srec --silent
    endif
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(GSREC_TOOL) -auto -o $(MODEL).mot $(MODEL).elf
    endif
	@echo Created S-record: $(MODEL).mot

#--------------------------------- Rules ---------------------------------------

ifeq ($(MODELREF_TARGET_TYPE),NONE)
ifeq ($(MAKEFILEBUILDER_TGT), 1)
#----------- MAKEFILEBUILDER_TGT = 1
$(MODEL).elf: $(PREBUILT_OBJS) $(OBJS) $(MODELLIB) $(SHARED_LIB) $(LIBS) $(SRC_DEP) $(MODELREF_LINK_LIBS)
	@echo ### Creating $(BUILD_PRODUCT_TYPE): $@
    ifeq ($(TARGET_COMPILER), GCC)
	$(LD) $(LD_OPTS) -T$(LD_FILE) $(PREBUILT_OBJS) $(OBJS) -Wl,--whole-archive $(MODELLIB) -Wl,--no-whole-archive $(MODELREF_LINK_LIBS) $(SHARED_LIB_LINK) $(LIBS) $(TOOL_LIB) -Wl,-Map,$(MODEL).map -o $@
    endif
    ifeq ($(TARGET_COMPILER), IAR)
	$(LD) $(LD_OPTS) --config $(LD_FILE) $(IAR_TARGET_LINK_OPTS) $(PREBUILT_OBJS) $(OBJS) $(MODELLIB) $(MODELREF_LINK_LIBS) $(SHARED_LIB_LINK) $(LIBS) $(TOOL_LIB) --map $(MODEL).map -o $@
    endif
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(CC) $(LD_OPTS) -keepmap -MD $(PREBUILT_OBJS) $(OBJS) $(MODELLIB) $(MODELREF_LINK_LIBS) $(SHARED_LIB_LINK) $(LIBS) $(TOOL_LIB) -Wl,-Map=$(MODEL).map -nostartfiles -T $(LD_FILE) -entry=Reset_Handler -o $@
    endif
	@echo ### Created $(BUILD_PRODUCT_TYPE): $@
else
ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
#----------- MAKEFILEBUILDER_TGT = 0  STANDALONE_SUPPRESS_EXE = 1
.PHONY: $(PRODUCT)
$(PRODUCT): $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP) $(MODELREF_LINK_LIBS)
	@echo ### Created $(BUILD_PRODUCT_TYPE): $(PRODUCT)
else
#----------- MAKEFILEBUILDER_TGT = 0  STANDALONE_SUPPRESS_EXE = 0
$(MODEL).elf: $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP) $(MODELREF_LINK_LIBS)
    ifeq ($(TARGET_COMPILER), GCC)
	$(LD) $(LD_OPTS) -T$(LD_FILE) $(OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB_LINK) $(LIBS) $(TOOL_LIB) -Wl,-Map,$(MODEL).map -o $@
    endif
    ifeq ($(TARGET_COMPILER), IAR)
	$(LD) $(LD_OPTS)--config $(LD_FILE) $(IAR_TARGET_LINK_OPTS) $(OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB_LINK) $(LIBS) $(TOOL_LIB) --map $(MODEL).map -o $@
    endif
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(CC) $(LD_OPTS) -keepmap  -MD $(OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB_LINK) $(LIBS) $(TOOL_LIB) -Wl,-Map=$(MODEL).map -nostartfiles -T $(LD_FILE) -entry=Reset_Handler -o $@
    endif
	@echo ### Created $(BUILD_PRODUCT_TYPE): $(PRODUCT)
endif
endif

else
ifeq ($(MODELREF_TARGET_TYPE),SIM)
else
$(MODELLIB): $(OBJS) $(SHARED_OBJS) $(SRC_DEP)
	@if exist $(MODELLIB) $(RM) "$(MODELLIB)"
    ifeq ($(TARGET_COMPILER), GCC)
	$(LIBCMD) -rv $@ $(LIBCMD_OPTS) $(OBJS) 
    endif
    ifeq ($(TARGET_COMPILER), IAR)
	$(LIBCMD) $@ $(LIBCMD_OPTS) $(OBJS) $(SHARED_OBJS)
    endif
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(LIBCMD) -Q -o $@ $(LIBCMD_OPTS) $(OBJS) $(SHARED_OBJS)
    endif
	@cmd /C "echo ### Created $(MODELLIB)"
	@cmd /C "echo ### Created $(BUILD_PRODUCT_TYPE): $@"
endif
endif

%.o : %.c
	@echo Building file $@...
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(CC)  -MD $(CC_OPTS) $(CFLAGS) -c -o $@ $<
    else
	$(CC) $(CC_OPTS) $(CFLAGS) $<
    endif

%.o : ../%.c
	@echo Building file $@...
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(CC) -MD $(CC_OPTS) $(CFLAGS) -c -o $@ $<
    else
	@$(CC) $(CC_OPTS) $(CFLAGS) $<
    endif

%.o : %.s
	@echo Building file $@...
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(AS) $(AS_OPTS) -o $@ $<
    else ifeq ($(TARGET_COMPILER), IAR)
	$(AS) $(AS_OPTS) -o $@ $<
    else
	$(AS) $(AS_OPTS) $<
    endif

%.o : ../%.s
	@echo Building file $@...
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(AS) $(AS_OPTS) -o $@ $<
    else ifeq ($(TARGET_COMPILER), IAR)
	$(AS) $(AS_OPTS) -o $@ $<
    else
	$(AS) $(AS_OPTS) $<
    endif

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@echo Building file $@...
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(CC)  -MD $(CC_OPTS) $(CFLAGS) -c -o $@ $<
    else
	$(CC) $(CC_OPTS) $(CFLAGS) $<
    endif

###################################
%.o : $(MATLAB_ROOT)\rtw\c\src/%.c
	@echo ### "$(MATLAB_ROOT)\rtw\c\src\$*.c"o
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(CC) -c -MD $(CC_OPTS) $(CFLAGS) -o $@ $<
    else
	@$(CC) $(CC_OPTS) $(CFLAGS) $<
    endif
%.o : $(MATLAB_ROOT)\simulink\src/%.c
	@echo ### "$(MATLAB_ROOT)\simulink\src\$*.c"o
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(CC) -c -MD $(CC_OPTS) $(CFLAGS) -o $@ $<
    else
	@$(CC) $(CC_OPTS) $(CFLAGS) $<
    endif


#----------------------------- Dependencies ------------------------------------

$(SHARED_LIB) : $(SHARED_OBJS)
	@cmd /C "echo ### Creating $@"
    ifeq ($(TARGET_COMPILER), GCC)
	$(LIBCMD) -rv $@ $(LIBCMD_OPTS) $(SHARED_OBJS)
    endif
    ifeq ($(TARGET_COMPILER), IAR)
	$(LIBCMD) $@ $(LIBCMD_OPTS) $(SHARED_OBJS)
    endif
    ifeq ($(TARGET_COMPILER), GreenHills Multi)
	$(LIBCMD) -Q -o $@ $(LIBCMD_OPTS) $(SHARED_OBJS)
    endif
	@cmd /C "echo ### $@ Created"

# EOF: mbd_s32k.tmf
