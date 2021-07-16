APP_NAME ?= stack_test
OUT ?= out/$(APP_NAME)
TAR ?= run

Q := #@
MD := $(Q)mkdir -p
RM := $(Q)rm -rf
CC := gcc

SRCS += $(wildcard $(abspath source/*.c))
INCS += $(wildcard $(abspath include))

SRCS += $(wildcard $(abspath app/$(APP_NAME))/*.c)
INCS += $(wildcard $(abspath app/$(APP_NAME)))

CFLAGS += -g
CFLAGS += -O0
CFLAGS += -Wall

SRCS := $(subst $(abspath $(CURDIR))/,,$(SRCS))
INCS := $(subst $(abspath $(CURDIR))/,,$(INCS))
OBJS := $(SRCS:%.c=$(OUT)/%.o)

default: run

$(OUT)/%.o: %.c
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCS:%=-I%) -c -o $@ $<

$(OUT)/$(TAR): $(OBJS)
	$(MD) $(dir $@)
	$(CC) $(CFLAGS) $(INCS:%=-I%) -o $@ $?

build: $(OUT)/$(TAR)

clean:
	$(RM) $(TAR)
	$(RM) $(OUT)

clean-build: clean build

run: $(OUT)/$(TAR)
	@echo
	@echo "[RUN $(APP_NAME)]"
	@echo
	@./$(OUT)/$(TAR)
