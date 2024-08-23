STRINGUTILS_DIR		:= $(SW_DIR)/stringUtils
STRINGUTILS_SRC_DIR	:= $(STRINGUTILS_DIR)/src

# STRINGUTILS_CXXFLAGS	:= 
# STRINGUTILS_LIBAR	:= libtraceifa.a # Static libary
# STRINGUTILS_LIBSO	:= libtraceif.so # Dynamic libary

# STRINGUTILS_SRCS	=
# STRINGUTILS_SRCS	+= traceIf.c

# STRINGUTILS_OBJS	:= $(STRINGUTILS_SRCS:%.c=$(OBJ_DIR)/%.o)

# STRINGUTILS_INCS	:= \
# 			-I$(STRINGUTILS_DIR)/if

# all: $(STRINGUTILS_OBJS) $(LIB_DIR)/$(STRINGUTILS_LIBAR) $(LIB_DIR)/$(STRINGUTILS_LIBSO) install-header-files-traceif
all: install-header-files-stringUtils

# Build target 1 objects
# $(OBJ_DIR)/%.o: $(STRINGUTILS_SRC_DIR)/%.c
# 	@mkdir -p $(@D)
# 	@cd $(<D)
# 	@echo "  CC \t\t $@"
# 	@$(SELF_CC) $^ $(SELF_LDFLAGS) $(SELF_CFLAGS) $(STRINGUTILS_CXXFLAGS) $(STRINGUTILS_INCS) -o $@

# $(LIB_DIR)/$(STRINGUTILS_LIBAR): $(STRINGUTILS_OBJS)
# 	@mkdir -p $(@D)
# 	@cd $(<D)
# 	@echo "  AR \t\t $@"
# 	@$(SELF_AR) $(SELF_ARFLAGS) $@ $^

# $(LIB_DIR)/$(STRINGUTILS_LIBSO): $(STRINGUTILS_OBJS)
# 	@mkdir -p $(@D)
# 	@cd $(<D)
# 	@echo "  CCLD \t\t $@"
# 	@$(SELF_CC) $(SELF_SOFLAGS) -o $@ $^

install-header-files-stringUtils:
	@mkdir -p $(INC_DIR)
	@echo "  COPY \t\t $(STRINGUTILS_DIR)/if"
	@$(SELF_CPY) $(STRINGUTILS_DIR)/if/*.h $(INC_DIR)

clean-stringUtils:
	@echo "  RMV \t\t $(BIN_DIR)/stringUtils"
#	@$(SELF_RMV) $(STRINGUTILS_OBJS) $(LIB_DIR)/$(STRINGUTILS_LIBAR) $(LIB_DIR)/$(STRINGUTILS_LIBSO)
	@$(SELF_RMV) $(INC_DIR)/stringUtils.h