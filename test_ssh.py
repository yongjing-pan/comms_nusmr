import paramiko

host = '192.168.153.136'
username = 'orangepi'
password = 'orangepi'

# host = '192.168.1.16'
# username = 'orinnx'
# password = 'pw'

client = paramiko.client.SSHClient()
client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
client.connect(host, username=username, password=password)
_stdin, _stdout,_stderr = client.exec_command("ls")
print(_stdout.read().decode())
client.close()