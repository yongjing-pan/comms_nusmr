import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/yongjing-ub22/comms_nusmr/mapviz_ws_YJ_laptop_only/install/path_publisher'
