from kivymd.app import MDApp
from kivy.uix.screenmanager import ScreenManager
from kivy.lang import Builder
from kivy.core.window import Window
#import serial

Window.size=(720,1480)

class Ui(ScreenManager):
    message = ''
    
    def textInput(self, widget):
        if widget.text!='' and len(widget.text)<=160:
            self.message = widget.text
            print(self.message)
            self.ids.mensaje.helper_text = 'Escribe un mensaje'
            self.ids.mensaje.text = ''
        elif len(widget.text)>160:
            self.ids.mensaje.helper_text = '¡No envíes un mensaje largo!'
        else:
            self.ids.mensaje.helper_text = '¡No envíes un mensaje vacío!'

    def buttonInput(self, string):
        self.message = string
        #try:
        #    seriall = serial.Serial(port=None,baudrate=9600)
        #    seriall.write(self.message)

        #except TimeoutError:
        #    print("error")
        #finally:
        #    print("done")
        print(self.message)

class MainApp(MDApp):

    def build(self):
        Builder.load_file('design.kv') #para la creación de los elementos de la app (widgets)
        return Ui()

if __name__ == "__main__":
    MainApp().run()
