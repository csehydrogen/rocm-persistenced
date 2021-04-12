bin_PROGRAMS = rocm-persistenced
LDADD = -lOpenCL
rocm_persistenced_SOURCES = main.cpp

if HAVE_SYSTEMD
dist_systemdsystemunit_DATA = rocm-persistenced.service
endif

DISTCHECK_CONFIGURE_FLAGS = CPPFLAGS=${CPPFLAGS}  LDFLAGS=${LDFLAGS}
AM_DISTCHECK_CONFIGURE_FLAGS = --with-systemdsystemunitdir=$$dc_install_base/$(systemdsystemunitdir)
