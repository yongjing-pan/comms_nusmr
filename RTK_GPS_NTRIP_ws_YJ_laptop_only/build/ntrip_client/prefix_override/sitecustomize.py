import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/yongjing-ub22/RTK_GPS_NTRIP_ws/install/ntrip_client'
