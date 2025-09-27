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
FINAL_IMAGE=${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU/7_Segment/ecu_7_segment.c ECU/BUTTON/ecu_button.c ECU/DC_MOTOR/ecu_dc_motor.c ECU/Keypad/ecu_keypad.c ECU/LED/ecu_led.c ECU/RELAY/ecu_relay.c ECU/RGB_LED/ecu_rgb_led.c MCAL/GPIO/hal_gpio.c MCAL/device_config.c application.c ECU/LCD/ecu_lcd.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1 ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU/LED/ecu_led.p1 ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1.d ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1.d ${OBJECTDIR}/ECU/LED/ecu_led.p1.d ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d ${OBJECTDIR}/MCAL/device_config.p1.d ${OBJECTDIR}/application.p1.d ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1 ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU/LED/ecu_led.p1 ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1 ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 ${OBJECTDIR}/MCAL/device_config.p1 ${OBJECTDIR}/application.p1 ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1

# Source Files
SOURCEFILES=ECU/7_Segment/ecu_7_segment.c ECU/BUTTON/ecu_button.c ECU/DC_MOTOR/ecu_dc_motor.c ECU/Keypad/ecu_keypad.c ECU/LED/ecu_led.c ECU/RELAY/ecu_relay.c ECU/RGB_LED/ecu_rgb_led.c MCAL/GPIO/hal_gpio.c MCAL/device_config.c application.c ECU/LCD/ecu_lcd.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1: ECU/7_Segment/ecu_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/7_Segment" 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1 ECU/7_Segment/ecu_7_segment.c 
	@-${MV} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.d ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/BUTTON/ecu_button.p1: ECU/BUTTON/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ECU/BUTTON/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU/BUTTON/ecu_button.d ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1: ECU/DC_MOTOR/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ECU/DC_MOTOR/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.d ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1: ECU/Keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Keypad" 
	@${RM} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1 ECU/Keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.d ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/ecu_led.p1: ECU/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/ecu_led.p1 ECU/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/ecu_led.d ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/ecu_relay.p1: ECU/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ECU/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/ecu_relay.d ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1: ECU/RGB_LED/ecu_rgb_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RGB_LED" 
	@${RM} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1 ECU/RGB_LED/ecu_rgb_led.c 
	@-${MV} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.d ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD/ecu_lcd.p1: ECU/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD" 
	@${RM} ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1 ECU/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD/ecu_lcd.d ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1: ECU/7_Segment/ecu_7_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/7_Segment" 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1 ECU/7_Segment/ecu_7_segment.c 
	@-${MV} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.d ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/7_Segment/ecu_7_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/BUTTON/ecu_button.p1: ECU/BUTTON/ecu_button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1 ECU/BUTTON/ecu_button.c 
	@-${MV} ${OBJECTDIR}/ECU/BUTTON/ecu_button.d ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/BUTTON/ecu_button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1: ECU/DC_MOTOR/ecu_dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/DC_MOTOR" 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1 ECU/DC_MOTOR/ecu_dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.d ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/DC_MOTOR/ecu_dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1: ECU/Keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/Keypad" 
	@${RM} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1 ECU/Keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.d ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/Keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/ecu_led.p1: ECU/LED/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/ecu_led.p1 ECU/LED/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/ecu_led.d ${OBJECTDIR}/ECU/LED/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/ecu_relay.p1: ECU/RELAY/ecu_relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1 ECU/RELAY/ecu_relay.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/ecu_relay.d ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/ecu_relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1: ECU/RGB_LED/ecu_rgb_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RGB_LED" 
	@${RM} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1 ECU/RGB_LED/ecu_rgb_led.c 
	@-${MV} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.d ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RGB_LED/ecu_rgb_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1: MCAL/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1 MCAL/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.d ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/device_config.p1: MCAL/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/device_config.p1 MCAL/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL/device_config.d ${OBJECTDIR}/MCAL/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD/ecu_lcd.p1: ECU/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD" 
	@${RM} ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1 ECU/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD/ecu_lcd.d ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

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
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC_Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
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

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
