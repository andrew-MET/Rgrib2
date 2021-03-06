#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "grib_api.h"
#include "R.h"
#include "Rinternals.h"

#define MAX_KEY_LEN 255
#define MAX_VAL_LEN 1024
#define MAX_HANDLE 15

/******************************************************************************/
/* This library links to grib_api (eccodes) and uses grib_handle structures.  */
/* But there is an added complexity due to the R interface. Some handles      */
/* must remain resident in R for analysis, while other are deleted on the fly.*/
/* So we work with an array GRIBhandleList[MAX_HANDLE] of RgribHandle*        */
/* which are structures with a pointer to the original grib_handle plus some  */
/* extra stuff to keep R happy.                                               */
/******************************************************************************/

typedef struct {
    int *id ;
    grib_handle *h;
    void *ext_ptr;
  } RgribHandle;

// extern RgribHandle* GRIBhandleList[MAX_HANDLE];

/* prototypes */

/***************/
/* bookkeeping */
/***************/
void Rgrib_init_check();
RgribHandle* Rgrib_create_handle();
void Rgrib_GRIBhandle_destroy(int i);
void Rgrib_clear_all_handles();
long Rgrib_count_handles_C();
SEXP Rgrib_count_handles();
SEXP Rgrib_list_handles();
SEXP Rgrib_clear_handle(SEXP gribhandle);
void Rgrib_handleFinalizer(SEXP gribhandle);

/*************************/
/* BASIC FILE OPERATIONS */
/*************************/

void Rgrib_count_messages(char** filename, int* nfields,int* multi);
SEXP Rgrib_parse_file(SEXP filename,
        SEXP IntPar, SEXP DblPar, SEXP StrPar, SEXP rec, SEXP multi);

/***************************/
/*  creating GRIBhandle's  */
/***************************/

SEXP Rgrib_handle_new_file(SEXP filename, SEXP message,SEXP multi);
SEXP Rgrib_handle_new_sample(SEXP sample);
SEXP Rgrib_handle_new_msg(SEXP msg, SEXP msglen);

/***************************/
/* DECODING HANDLES & INFO */
/***************************/

SEXP Rgrib_handle_parse_all(SEXP gribhandle);
SEXP Rgrib_handle_info(SEXP gribhandle,SEXP StrPar, SEXP IntPar, SEXP DblPar);
SEXP Rgrib_handle_decode(SEXP gribhandle);

/************/
/* ENCODING */
/************/

SEXP Rgrib_handle_mod(SEXP gribhandle,SEXP StrPar, SEXP IntPar, SEXP DblPar);
SEXP Rgrib_handle_enc(SEXP gribhandle,SEXP fieldvalues);
SEXP Rgrib_handle_write(SEXP gribhandle,SEXP filename,SEXP filemode);


