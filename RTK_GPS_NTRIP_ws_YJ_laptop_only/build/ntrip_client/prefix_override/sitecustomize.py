import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/yongjing-ub22/comms_nusmr/RTK_GPS_NTRIP_ws_YJ_laptop_only/install/ntrip_client'
