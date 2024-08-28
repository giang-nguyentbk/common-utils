# --------------------------------------------------
# Call Makefiles for init setups and build database
# --------------------------------------------------
include Makefile.config

# --------------------------------------------------
# Call Makefiles for modules of the project
# --------------------------------------------------
include $(SW_DIR)/traceIf/Makefile
include $(SW_DIR)/stringUtils/Makefile
include $(SW_DIR)/enumUtils/Makefile


all: rootMakefile

rootMakefile:
	@echo
	@echo "sw/make/Makefile: Compilation $(PROJ_NAME) done!!! [OK]"

clean:
	@echo
	@echo "  RMV \t\t $(BIN_DIR)"
	@$(SELF_RMV) $(BIN_DIR)