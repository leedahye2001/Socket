import socket
import threading

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('', 8888))
nickname = input("Username: ")


def receive():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if message == 'USERNAME':
                client.send(nickname.encode('utf-8'))
            else:
                print(message)
        except:
            print("에러가 발생했습니다!")
            client.close()
            break

#강아지@192.168.1.2:2000]
def write():
    while True:
        #message = '{}@{}:{}:{} '.format(nickname,host,port, input(''))
        message = '{} : {} '.format(nickname, input(''))
        print(nickname + ": ")
        client.send(message.encode('utf-8'))


# 멀티 클라이언트용 쓰레드
receive_thread = threading.Thread(target=receive)
receive_thread.start()

# 메시지 보내기
write_thread = threading.Thread(target=write)
write_thread.start()