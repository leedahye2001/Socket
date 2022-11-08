import socket
import threading

host = ''
port = 8888

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()

# 서버에 접속한 클라이언트 목록
clients = []
# 접속한 닉네임 목록
nicknames = []


# 서버가 받은 메시지를 클라이언트 전체에 보내기
def broadcast(message):
    for client in clients:
        client.send(message)


def handle(client):
    while True:
        try:
            # 클라이언트로부터 타당한 메시지를 받았는지 확인
            message = client.recv(1024)
            broadcast(message)

        except:
            # 클라이언트가 나갔으면 알림
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]

            broadcast("{} 명이 채팅방에 남아있습니다!\n".format(len(nicknames)).encode('utf-8'))
            nicknames.remove(nickname)
            break


# 멀티 클라이언트를 받는 메서드
def receive():
        while True:
            client, address = server.accept()

            print("Connected with {}".format(str(address)))

            client.send('USERNAME'.encode('utf-8'))
            nickname = client.recv(1024).decode('utf-8')
            nicknames.append(nickname)
            clients.append(client)

            print("Username : {}".format(nickname))
            broadcast("[ {} 님이 입장하셨습니다! ]\n".format(nickname).encode('utf-8'))
            broadcast("[ {} 명이 이 채팅방 안에 있습니다! ]\n".format(len(nicknames)).encode('utf-8'))
            client.send('-- 서버와 연결되었습니다. --'.encode('utf-8'))
            thread = threading.Thread(target=handle, args=(client,))
            thread.start()


receive()