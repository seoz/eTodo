SUBDIRS = src
.PHONY: subdirs $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@
