import socket
import threading

host = ""
port = 8000
usernames = {}

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((host, port))
# 3명의 클라이언트만 들어오게
server_socket.listen(3)

def msg_function(message):
    print(message)
    for conn in usernames.values():
        try:
            conn.send(message.encode('utf-8'))
        except:
            print("연결이 끊어졌습니다.")

def handle_receive(client_socket, address, username):
    print("Username : {}".format(username))
    msg = "\n[ %s @ %s : %s 님이 입장하셨습니다. ]" % (username, address[0], address[1])
    msg_function(msg)

    while True:
        data = client_socket.recv(1024)
        string = data.decode('utf-8')

        if "/quit" in string:
            msg = "---- %s @ %s : %s 님이 퇴장하셨습니다. ----" % (username, address[0], address[1])

            # 유저 목록에서 방금 종료한 유저의 정보를 삭제
            del usernames[username]
            msg_function(msg)
            break

        string = "%s @ %s : %s] %s" % (username, address[0], address[1], string)
        msg_function(string)
    client_socket.close()

def handle_notice(client_socket, address, user):
    pass

def accept_func():
    print('[ 서버와 연결되었습니다. ]')

    while True:
        try:
            # 클라이언트 함수가 접속 시, 새로운 소켓 반환
            client_socket, address = server_socket.accept()
            print("Connected with [ {} : {} ]".format(str(address[0]), str(address[1])))

        except KeyboardInterrupt:
            for user, conn in usernames:
                conn.close()
            server_socket.close()
            print("Keyboard interrupt")
            break

        username = client_socket.recv(1024).decode('utf-8')
        usernames[username] = client_socket

        notice_thread = threading.Thread(target=handle_notice, args=(client_socket, address, username))
        notice_thread.daemon = True
        notice_thread.start()

        receive_thread = threading.Thread(target=handle_receive, args=(client_socket, address, username))
        receive_thread.daemon = True
        receive_thread.start()


if __name__ == '__main__':
    accept_func()
