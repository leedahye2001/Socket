import socket
import threading

host = ''
port = 8000

print("[ 채팅에 들어오신 것을 환영합니다! ]\n-- 채팅을 마치고 싶으시면  /quit  를 입력해주세요. --")
username = input("\nUsername : ")

def handle_receive(client_socket, user):
    while True:
        try:
            data = client_socket.recv(1024)
        except:
            print("--- 연결이 끊어졌습니다. ---")
            break
        data = data.decode('utf-8')
        if not user in data:
            print(data)


def handle_send(client_socket):
    while True:
        data = input()
        client_socket.send(data.encode('utf-8'))
        if data == "/quit":
            break
    client_socket.close()


if __name__ == '__main__':
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))
    client_socket.send(username.encode('utf-8'))

    receive_thread = threading.Thread(target=handle_receive, args=(client_socket, username))
    receive_thread.daemon = True
    receive_thread.start()

    send_thread = threading.Thread(target=handle_send, args=(client_socket,))
    send_thread.daemon = True
    send_thread.start()

    send_thread.join()
    receive_thread.join()
