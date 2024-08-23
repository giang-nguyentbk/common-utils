ENUMUTILS_DIR		:= $(SW_DIR)/enumUtils
ENUMUTILS_SRC_DIR	:= $(ENUMUTILS_DIR)/src

all: install-header-files-enumUtils

install-header-files-enumUtils:
	@mkdir -p $(INC_DIR)
	@echo "  COPY \t\t $(ENUMUTILS_DIR)/if"
	@$(SELF_CPY) $(ENUMUTILS_DIR)/if/*.h $(INC_DIR)

clean-enumUtils:
	@echo "  RMV \t\t $(BIN_DIR)/enumUtils"
	@$(SELF_RMV) $(INC_DIR)/enumUtils.h