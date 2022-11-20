from kivymd.app import MDApp
from kivy.uix.screenmanager import ScreenManager
from kivy.lang import Builder
from kivy.core.window import Window
from kivymd.toast import toast
from jnius import autoclass
from android.permissions import Permission, request_permissions

BluetoothAdapter = autoclass('android.bluetooth.BluetoothAdapter')
BluetoothDevice = autoclass('android.bluetooth.BluetoothDevice')
BluetoothSocket = autoclass('android.bluetooth.BluetoothSocket')
UUID = autoclass('java.util.UUID')

def get_socket_stream():
    paired_devices = BluetoothAdapter.getDefaultAdapter().getBondedDevices().toArray()
    #toast("Paired devices: SUCCESS")#, duration=5)
    socket = None
    for device in paired_devices:
        toast("ciclo {0}: SUCCESS".format(device.getName()))#,duration=5)
        #if device.getName() == name:
        #toast("Dispositivo {0} encontrado: SUCCESS".format(device.getName()),)# duration=5)
        socket = device.createRfcommSocketToServiceRecord(
            UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"))
        #toast("socket: SUCCESS")#, duration=5)
        recv_stream = socket.getInputStream()
        #toast("Input Stream: SUCCESS")#, duration=5)
        send_stream = socket.getOutputStream()
        #toast("Output Stream: SUCCESS")#, duration=5)
        break
    socket.connect()
    toast("Conexión: SUCCESS")
    return recv_stream, send_stream

Window.size=(720,1480)

class Ui(ScreenManager):
    message = ''
    def send(self, cmd):
      self.send_stream.write(cmd.encode())
      self.send_stream.flush()

    def textInput(self, widget):
        if widget.text!='' and len(widget.text)<=160:
            self.message = widget.text
            print(self.message)
            self.ids.mensaje.helper_text = 'Escribe un mensaje'
            self.ids.mensaje.text = ''
            toast(self.message)
            self.send(self.message)
        elif len(widget.text)>160:
            self.ids.mensaje.helper_text = '¡No envíes un mensaje largo!'
        else:
            self.ids.mensaje.helper_text = '¡No envíes un mensaje vacío!'

    def buttonInput(self, string):
        self.message = string.lower()
        toast(self.message)
        print(self.message)
        self.send(self.message)

    def conectar(self):
        toast("Empezando conexión")
        self.recv_stream, self.send_stream = get_socket_stream()
        toast("Conexión finalizada")

class MainApp(MDApp):

    def build(self):
        def callback(permission, results):
          if all([res for res in results]):
            toast("Con su permiso :)")
          else:
            toast("Sin su permiso :(")
        request_permissions([Permission.BLUETOOTH, Permission.BLUETOOTH_ADMIN], callback)
        Builder.load_file('design.kv') #para la creación de los elementos de la app (widgets)
        return Ui()

if __name__ == "__main__":
    MainApp().run()
