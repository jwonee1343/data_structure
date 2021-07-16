APP_NAME ?= stack_test
OUT ?= out
TAR ?= out/$(APP_NAME)

Q := @
MD := $(Q)mkdir -p
RM := $(Q)rm -rf
CC := $(Q)gcc

SRCS += $(wildcard source/*.c)
INCS += $(wildcard include)

SRCS += $(wildcard app/$(APP_NAME)/*.c)
INCS += $(wildcard app/$(APP_NAME))

CFLAGS += -g
CFLAGS += -Os
CFLAGS += -Wall

OBJS := $(SRCS:%.c=$(OUT)/%.o)

default: run

$(OUT)/%.o: %.c
	@echo "Compiling $<..."
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCS:%=-I%) -MMD -MD -MF $(@:%.o=%.d) -c -o $@ $<

$(OUT)/$(TAR): $(OBJS)
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCS:%=-I%) -Wl,-Map $@.map -o $@ $?

build: $(OUT)/$(TAR)

clean:
	$(RM) $(TAR)
	$(RM) $(OUT)

clean-build: clean build

run: $(OUT)/$(TAR)
	@echo "[$(APP_NAME)]"
	@./$(OUT)/$(TAR)
