#Rgrib2
### a R package to decode and encode GRIB data

This R package is an api to the *grib_api* library developed by ECMWF, with several functionalities added.

The data fields are coded as matrices with attributes to describe projection and grid specifications.

Usually, this package will be used together with the companion package *meteogrid*.

##C CODE

This package requires the library *grib_api* (versions <=2012 are GPL, more recent versions use the Apache license) developped by ECMWF and available from https://software.ecmwf.int/wiki/display/GRIB/Home

This package also usually requires the PROJ.4 library for projections.

#EARTH RADIUS
In GRIB-1 files, the Earth radius is not defined explicitely. However, the WMO standard value differs from that used at ECMWF and in the ALADIN consortium. This code uses our default value!!!

### ATTENTION: the WMO standard for GRIB-1 files has earth radius a=6367470.0
###            On the other hand, NCEP uses a=6371200.0 (also hardcoded in grads)
###            and the ALADIN model a=6371229.0
###            In GRIB-1 it is not possible to pass the Earth radius.
###            In GRIB-2, there is a parameter 'earth shape'. Value 0 corresponds
###            to the grib-1 sphere, while value 6 corresponds to the sphere as uses by ECMWF and ALADIN.
### strangely, grib_api returns shape="6" and radius 6367470.0 for grib-1 files. This is inconsistent!

##License
Copyright 2003-2019, Alex Deckmyn, Royal Meteorological Institute of Belgium
alex.deckmyn@meteo.be
