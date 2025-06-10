#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=lib/src/buttons.c lib/src/i2c.c lib/src/oc.c lib/src/pwm.c lib/src/servo.c lib/src/shell.c lib/src/spiflash.c lib/src/srf.c lib/src/timer.c lib/src/uart.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/lib/src/buttons.o ${OBJECTDIR}/lib/src/i2c.o ${OBJECTDIR}/lib/src/oc.o ${OBJECTDIR}/lib/src/pwm.o ${OBJECTDIR}/lib/src/servo.o ${OBJECTDIR}/lib/src/shell.o ${OBJECTDIR}/lib/src/spiflash.o ${OBJECTDIR}/lib/src/srf.o ${OBJECTDIR}/lib/src/timer.o ${OBJECTDIR}/lib/src/uart.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/lib/src/buttons.o.d ${OBJECTDIR}/lib/src/i2c.o.d ${OBJECTDIR}/lib/src/oc.o.d ${OBJECTDIR}/lib/src/pwm.o.d ${OBJECTDIR}/lib/src/servo.o.d ${OBJECTDIR}/lib/src/shell.o.d ${OBJECTDIR}/lib/src/spiflash.o.d ${OBJECTDIR}/lib/src/srf.o.d ${OBJECTDIR}/lib/src/timer.o.d ${OBJECTDIR}/lib/src/uart.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/lib/src/buttons.o ${OBJECTDIR}/lib/src/i2c.o ${OBJECTDIR}/lib/src/oc.o ${OBJECTDIR}/lib/src/pwm.o ${OBJECTDIR}/lib/src/servo.o ${OBJECTDIR}/lib/src/shell.o ${OBJECTDIR}/lib/src/spiflash.o ${OBJECTDIR}/lib/src/srf.o ${OBJECTDIR}/lib/src/timer.o ${OBJECTDIR}/lib/src/uart.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=lib/src/buttons.c lib/src/i2c.c lib/src/oc.c lib/src/pwm.c lib/src/servo.c lib/src/shell.c lib/src/spiflash.c lib/src/srf.c lib/src/timer.c lib/src/uart.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX370F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lib/src/buttons.o: lib/src/buttons.c  .generated_files/flags/default/3d2159e6647bdfa164379d4c807d994f78fbd0b6 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/buttons.o.d 
	@${RM} ${OBJECTDIR}/lib/src/buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/buttons.o.d" -o ${OBJECTDIR}/lib/src/buttons.o lib/src/buttons.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/i2c.o: lib/src/i2c.c  .generated_files/flags/default/3c9184421803a37f0da76b6ddb0306129c2bcf57 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/lib/src/i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/i2c.o.d" -o ${OBJECTDIR}/lib/src/i2c.o lib/src/i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/oc.o: lib/src/oc.c  .generated_files/flags/default/55b6c28f86c9ef7a328b582cf780f8a2137587fa .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/oc.o.d 
	@${RM} ${OBJECTDIR}/lib/src/oc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/oc.o.d" -o ${OBJECTDIR}/lib/src/oc.o lib/src/oc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/pwm.o: lib/src/pwm.c  .generated_files/flags/default/d8f1ca96e56309f261cbff9ce4ec6a5885fb3188 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/lib/src/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/pwm.o.d" -o ${OBJECTDIR}/lib/src/pwm.o lib/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/servo.o: lib/src/servo.c  .generated_files/flags/default/d9ad52421ef22882d6c7b15a98fcbb143f5d5d4c .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/servo.o.d 
	@${RM} ${OBJECTDIR}/lib/src/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/servo.o.d" -o ${OBJECTDIR}/lib/src/servo.o lib/src/servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/shell.o: lib/src/shell.c  .generated_files/flags/default/2798b2ba167fac9cf72947995591613f28a44f83 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/shell.o.d 
	@${RM} ${OBJECTDIR}/lib/src/shell.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/shell.o.d" -o ${OBJECTDIR}/lib/src/shell.o lib/src/shell.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/spiflash.o: lib/src/spiflash.c  .generated_files/flags/default/82ed67b24cf1804799d97548eb8fdf7a4826abe8 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/spiflash.o.d 
	@${RM} ${OBJECTDIR}/lib/src/spiflash.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/spiflash.o.d" -o ${OBJECTDIR}/lib/src/spiflash.o lib/src/spiflash.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/srf.o: lib/src/srf.c  .generated_files/flags/default/8819c4aad541c632c2c5fd97dbcedb3ee5e7c44f .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/srf.o.d 
	@${RM} ${OBJECTDIR}/lib/src/srf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/srf.o.d" -o ${OBJECTDIR}/lib/src/srf.o lib/src/srf.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/timer.o: lib/src/timer.c  .generated_files/flags/default/a9934983b7cd1d7341d13b65df2ae3207f904ba6 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/timer.o.d 
	@${RM} ${OBJECTDIR}/lib/src/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/timer.o.d" -o ${OBJECTDIR}/lib/src/timer.o lib/src/timer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/uart.o: lib/src/uart.c  .generated_files/flags/default/e8f27157fcd9608a8b9ac21d056ae453afec835a .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/uart.o.d 
	@${RM} ${OBJECTDIR}/lib/src/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/uart.o.d" -o ${OBJECTDIR}/lib/src/uart.o lib/src/uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/467ddbb94513e215b17fe00386a263330277b8a .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/lib/src/buttons.o: lib/src/buttons.c  .generated_files/flags/default/cd2c82ccd266c2e01fb9fc0380c7df4d2e86b597 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/buttons.o.d 
	@${RM} ${OBJECTDIR}/lib/src/buttons.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/buttons.o.d" -o ${OBJECTDIR}/lib/src/buttons.o lib/src/buttons.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/i2c.o: lib/src/i2c.c  .generated_files/flags/default/931a83eb1a5254be0e88ddc9bbb9657a084be889 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/i2c.o.d 
	@${RM} ${OBJECTDIR}/lib/src/i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/i2c.o.d" -o ${OBJECTDIR}/lib/src/i2c.o lib/src/i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/oc.o: lib/src/oc.c  .generated_files/flags/default/7c8e930777c3a5926e21c03f99b185cc531381c5 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/oc.o.d 
	@${RM} ${OBJECTDIR}/lib/src/oc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/oc.o.d" -o ${OBJECTDIR}/lib/src/oc.o lib/src/oc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/pwm.o: lib/src/pwm.c  .generated_files/flags/default/b1efbddd64e7f2f16a9d23cdbfbc1dbefc6614d2 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/lib/src/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/pwm.o.d" -o ${OBJECTDIR}/lib/src/pwm.o lib/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/servo.o: lib/src/servo.c  .generated_files/flags/default/d4b9012d78fcfd0bf1a2e6b267e91d0d4be156ff .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/servo.o.d 
	@${RM} ${OBJECTDIR}/lib/src/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/servo.o.d" -o ${OBJECTDIR}/lib/src/servo.o lib/src/servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/shell.o: lib/src/shell.c  .generated_files/flags/default/cb160108476a3dec23cd03d577295529b5bc8dd9 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/shell.o.d 
	@${RM} ${OBJECTDIR}/lib/src/shell.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/shell.o.d" -o ${OBJECTDIR}/lib/src/shell.o lib/src/shell.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/spiflash.o: lib/src/spiflash.c  .generated_files/flags/default/330d3327665443eb0d688cbfd3bd215b35043d6f .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/spiflash.o.d 
	@${RM} ${OBJECTDIR}/lib/src/spiflash.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/spiflash.o.d" -o ${OBJECTDIR}/lib/src/spiflash.o lib/src/spiflash.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/srf.o: lib/src/srf.c  .generated_files/flags/default/b8bd8b635f2c40a6ca3e12969835645096db5867 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/srf.o.d 
	@${RM} ${OBJECTDIR}/lib/src/srf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/srf.o.d" -o ${OBJECTDIR}/lib/src/srf.o lib/src/srf.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/timer.o: lib/src/timer.c  .generated_files/flags/default/b228a35b2258d9705a77b6286a9562cfe3fad601 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/timer.o.d 
	@${RM} ${OBJECTDIR}/lib/src/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/timer.o.d" -o ${OBJECTDIR}/lib/src/timer.o lib/src/timer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/lib/src/uart.o: lib/src/uart.c  .generated_files/flags/default/5e51e7b77d401124804fcae7432ad19111b56e19 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/uart.o.d 
	@${RM} ${OBJECTDIR}/lib/src/uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/lib/src/uart.o.d" -o ${OBJECTDIR}/lib/src/uart.o lib/src/uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/867d0b8786cc52a03d5ef4ea540e07e905ef1540 .generated_files/flags/default/6438250107dfc27639d39317b40d1e2c3667782e
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"lib/inc" -I"lib/src" -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/EMBC_A_1_4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
