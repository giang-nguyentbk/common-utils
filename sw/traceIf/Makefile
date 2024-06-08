TRACEIF_DIR		:= $(SW_DIR)/traceIf
TRACEIF_SRC_DIR		:= $(TRACEIF_DIR)/src

TRACEIF_CXXFLAGS	:= 
TRACEIF_LIBAR		:= libtraceifa.a # Static libary
TRACEIF_LIBSO		:= libtraceif.so # Dynamic libary

TRACEIF_SRCS		=
TRACEIF_SRCS		+= traceIf.c

TRACEIF_OBJS		:= $(TRACEIF_SRCS:%.c=$(OBJ_DIR)/%.o)

TRACEIF_INCS		:= \
			-I$(TRACEIF_DIR)/if

all: $(TRACEIF_OBJS) $(LIB_DIR)/$(TRACEIF_LIBAR) $(LIB_DIR)/$(TRACEIF_LIBSO) install-header-files-traceif

# Build target 1 objects
$(OBJ_DIR)/%.o: $(TRACEIF_SRC_DIR)/%.c
	@mkdir -p $(@D)
	@cd $(<D)
	@echo "  CC \t\t $@"
	@$(SELF_CC) $^ $(SELF_LDFLAGS) $(SELF_CFLAGS) $(TRACEIF_CXXFLAGS) $(TRACEIF_INCS) -o $@

$(LIB_DIR)/$(TRACEIF_LIBAR): $(TRACEIF_OBJS)
	@mkdir -p $(@D)
	@cd $(<D)
	@echo "  AR \t\t $@"
	@$(SELF_AR) $(SELF_ARFLAGS) $@ $^

$(LIB_DIR)/$(TRACEIF_LIBSO): $(TRACEIF_OBJS)
	@mkdir -p $(@D)
	@cd $(<D)
	@echo "  CCLD \t\t $@"
	@$(SELF_CC) $(SELF_SOFLAGS) -o $@ $^

install-header-files-traceif:
	@mkdir -p $(INC_DIR)
	@echo "  CPY \t\t $(TRACEIF_DIR)/if"
	@$(SELF_CPY) $(TRACEIF_DIR)/if/*.h $(INC_DIR)

clean-traceif:
	$(SELF_RMV) $(TRACEIF_OBJS) $(LIB_DIR)/$(TRACEIF_LIBAR) $(LIB_DIR)/$(TRACEIF_LIBSO)