BUILD_DIR = build


all: cmake
.PHONY: all


cmake: $(BUILD_DIR)
	cd $(BUILD_DIR); cmake $(CURDIR); make
.PHONY: cmake


$(BUILD_DIR):
	mkdir -p $@


run:
	$(BUILD_DIR)/exit_app
.PHONY: run


clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean
