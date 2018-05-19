TOP := $(CURDIR)
BUILD := $(TOP)/build
MAKE := $(MAKE) -j$(shell grep -c ^processor /proc/cpuinfo)
CMAKE := cmake

all:
	test -d $(BUILD) || (mkdir -p $(BUILD) && cd $(BUILD) && $(CMAKE) -D CMAKE_BUILD_TYPE=RelWithDebInfo $(TOP))
	cd $(BUILD) && $(MAKE)
.PHONY: all


prebuild:
	mkdir -p $(BUILD) || true
.PHONY: prebuild


debug: prebuild
	cd $(BUILD) && $(CMAKE) -D CMAKE_BUILD_TYPE=Debug $(TOP) && $(MAKE)
.PHONY: debug


release: prebuild
	cd $(BUILD) && $(CMAKE) -D CMAKE_BUILD_TYPE=Release $(TOP) && $(MAKE)
.PHONY: release


relwithdebinfo: prebuild
	cd $(BUILD) && $(CMAKE) -D CMAKE_BUILD_TYPE=RelWithDebInfo $(TOP) && $(MAKE)
.PHONY: relwithdebinfo


minsizerel: prebuild
	cd $(BUILD) && $(CMAKE) -D CMAKE_BUILD_TYPE=MinSizeRel $(TOP) && $(MAKE)
.PHONY: minsizerel


install: relwithdebinfo
	cd $(BUILD) && $(MAKE) install
.PHONY: install


uinstall:
	cd $(BUILD) && $(CMAKE) -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=~/.local $(TOP) && $(MAKE) && $(MAKE) install
.PHONY: uinstall


clean:
	-(cd $(BUILD) && $(MAKE) clean)
.PHONY: clean
c: clean


distclean:
	-rm -rf $(BUILD)
.PHONY: distclean
dc: distclean
