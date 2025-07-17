#ifndef TEL_VERSION_H
#define TEL_VERSION_H

#define TEL_VERSION_PREFIX "r"
#define TEL_VERSION_MAJOR  0
#define TEL_VERSION_MINOR  1
#define TEL_VERSION_PATCH  5

#define TEL_VERSION                                                            \
  TEL_VERSION_PREFIX #TEL_VERSION_MAJOR "." #TEL_VERSION_MINOR                 \
                                        "." #TEL_VERSION_PATCH

#endif // !TEL_VERSION
