#ifndef DCUBE_NULLTB_H
#define DCUBE_NULLTB_H

/* NULLTB period in seconds (0 is aperiodic) */
#if TB_CONF_NULLTB_PERIOD
#define TB_PERIOD                     (CLOCK_SECOND * TB_CONF_NULLTB_PERIOD)
#else
#define TB_PERIOD                     0
#endif
/* NULLTB aperiodic MIN in seconds */
#if TB_CONF_NULLTB_PERIOD_MIN
#define TB_PERIOD_MIN                 (CLOCK_SECOND * TB_CONF_NULLTB_PERIOD_MIN)
#else
#define TB_PERIOD_MIN                 (CLOCK_SECOND * 2)
#endif
/* NULLTB aperiodic MAX in seconds */
#if TB_CONF_NULLTB_PERIOD_MAX
#define TB_PERIOD_MAX                 (CLOCK_SECOND * TB_CONF_NULLTB_PERIOD_MAX)
#else
#define TB_PERIOD_MAX                 (CLOCK_SECOND * 5)
#endif

#if TB_CONF_NULLTB_DATA_LEN
#define TB_DATA_LEN                   TB_CONF_NULLTB_DATA_LEN
#else
#define TB_DATA_LEN                   8
#endif

#if TB_CONF_NULLTB_MAX_SRC_DEST
#define TB_MAX_SRC_DEST               TB_CONF_NULLTB_MAX_SRC_DEST
#else
#define TB_MAX_SRC_DEST               8
#endif

#if TB_CONF_NULLTB_NUMPATTERN
#define TB_NUMPATTERN                 TB_CONF_NULLTB_NUMPATTERN
#else
#define TB_NUMPATTERN                 8
#endif

#endif /* DCUBE_NULLTB_H */
