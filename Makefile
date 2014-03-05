BUILD_DIR = build
BUILD_TYPE ?= Release


all: cmake


debug:
	BUILD_TYPE=Debug $(MAKE)


coverage:
	BUILD_TYPE=TestCoverage $(MAKE) test
	lcov --capture --directory $(BUILD_DIR) \
		--output-file $(BUILD_DIR)/coverage.info
	genhtml $(BUILD_DIR)/coverage.info \
		--output-directory $(BUILD_DIR)/coverage-report


test: $(BUILD_DIR)
	cd $(BUILD_DIR); cmake \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		$(CURDIR); \
		make build_test; \
		make test


cmake: $(BUILD_DIR)
	cd $(BUILD_DIR); cmake \
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE) \
		$(CURDIR); \
		make


doc: $(BUILD_DIR)
	doxygen doc/Doxyfile


$(BUILD_DIR):
	mkdir -p $@


clean:
	rm -rf $(BUILD_DIR)


.PHONY: all cmake clean doc test test-coverage
