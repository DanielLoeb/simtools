## Makefile.am -- Use automake to produce a makefile.in from this

AM_CPPFLAGS = -I$(top_srcdir) -DHAVE_CONFIG_H

AM_CXXFLAGS =\
    -Wall

AM_CFLAGS=$(AM_CXXFLAGS)

libsimtoolsdir = $(libdir)
libsimtools_LTLIBRARIES = libsimtools.la

libsimtools_la_SOURCES = twoe.cpp exceptions.cpp
libsimtools_la_includedir = $(includedir)/simtools
libsimtools_la_include_HEADERS = binary_sum_search.hh growing_binary_search.hh twoe.hh binary_heap.hh exceptions.hh red_black_tree.hh ../config.h

libsimtools_la_LIBADD = $(MOD_LIBADD)
libsimtools_la_LDFLAGS = $(MOD_LDFLAGS)
