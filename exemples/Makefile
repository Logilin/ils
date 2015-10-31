SUBDIRS=            \
	chapitre-02 \
	chapitre-03 \
	chapitre-04 \
	chapitre-05 \
	chapitre-06 \

all:
	@set -e;                \
	for i in $(SUBDIRS);    \
	do                      \
		if [ -d $$i ]; then	\
		cd $$i;             \
		make;               \
		cd -;               \
		fi;                 \
	done

clean: 
	@set -e;                \
	for i in $(SUBDIRS);    \
	do                      \
		if [ -d $$i ]; then \
		cd $$i;             \
		make clean;         \
		cd -;               \
		fi;                 \
	done

