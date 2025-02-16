import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/yongjing-ub22/comms_nusmr/simple_pubsub_ws/install/py_pubsub'
