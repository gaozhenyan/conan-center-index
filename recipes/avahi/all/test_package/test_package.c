#include <malloc.h>
#include <stdlib.h>

#include "dns_sd.h"
#include <avahi-core/log.h>
#include <avahi-common/malloc.h>
#include <avahi-common/error.h>

int main(void) {
    DNSServiceRef sdRef;
    DNSServiceErrorType err = DNSServiceBrowse(&sdRef, 0, 0, "_example._tcp", NULL, NULL, NULL);
    if (err == kDNSServiceErr_NoError)
    {
        avahi_log_error("DNSServiceBrowse succeeded\n");
        DNSServiceRefDeallocate(sdRef);
    }
    else
    {
        avahi_log_info("DNSServiceBrowse failed: %d\n", err);
    }
    malloc_trim(0);  // from <malloc.h>
    return EXIT_SUCCESS;
}
