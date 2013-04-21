#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

include $(DEVKITARM)/ds_rules

export TARGET		:=	ZDS
export TOPDIR		:=	$(shell cd ../ && pwd)
export TARGETDIR	= $(TOPDIR)/Bin
export OBJDIR		= $(TOPDIR)/Obj


.PHONY: ARM7/$(TARGET).elf ARM9/$(TARGET).elf $(TARGETDIR)

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
all: $(TARGET).nds

$(TARGETDIR):
	@[ -d $@ ] || mkdir -p $@

#---------------------------------------------------------------------------------
$(TARGET).nds	:	$(TARGETDIR) $(OBJDIR)/ARM7/$(TARGET).elf $(OBJDIR)/ARM9/$(TARGET).elf
	ndstool	-c $(TARGETDIR)/$(TARGET).nds -7 $(OBJDIR)/ARM7/$(TARGET).elf -9 $(OBJDIR)/ARM9/$(TARGET).elf

#---------------------------------------------------------------------------------
$(OBJDIR)/ARM7/$(TARGET).elf:
	$(MAKE) -C ARM7
	
#---------------------------------------------------------------------------------
$(OBJDIR)/ARM9/$(TARGET).elf:
	$(MAKE) -C ARM9

#---------------------------------------------------------------------------------
clean:
	$(MAKE) -C ARM9 clean
	$(MAKE) -C ARM7 clean
	rm -f $(TARGETDIR)/$(TARGET).nds

cleanelf:
	rm -rf $(OBJDIR)/ARM9/*.elf
	rm -rf $(OBJDIR)/ARM7/*.elf
