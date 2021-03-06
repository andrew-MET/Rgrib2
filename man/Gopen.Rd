\name{Gopen}
\alias{Gopen}
\alias{GRIB open}
\title{Open a Grib file}
\description{
  Reads the basic information of a Grib file (not the data itself).
}
\usage{
  Gopen(filename,IntPar = c("editionNumber", "dataDate", "dataTime", 
    "validityDate", "validityTime", "Nx", "Ny", "table2Version", 
    "indicatorOfParameter", "parameterCategory", "parameterNumber",
    "indicatorOfTypeOfLevel", "level"), 
    DblPar = c(), StrPar = c("shortName", "gridType"),
    multi = FALSE,lextra=TRUE) 
}
\arguments{
  \item{filename}{A character string pointing at a GRIB file.}
  \item{IntPar,DblPar,StrPar}{The list of keys to be read for all records in the file.}
  \item{multi}{If TRUE, multi-field messages are allowed.}
  \item{lextra}{If TRUE, the GRIB-1 records not recognized by grib_api are matched to an internal table with some extra table2 versions.}
}
\value{
  a data.frame of class \code{GRIBlist}, containing the basic information of the data in the file. 
}
\seealso{
  \code{\link{Ginfo}}, \code{\link{Gdec}}, \code{\link{iview}}
}
\examples{\dontrun{
#Get first 5 records of a file.
mylist <- Gopen('filename')
#one grib record:
mylist[1,]
Gdec(mylist,1)
}}
\keyword{file}
