object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 405
  ClientWidth = 434
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  TextHeight = 15
  object Image1: TImage
    Left = 328
    Top = 24
    Width = 65
    Height = 57
    Proportional = True
    Stretch = True
    OnClick = Image1Click
    OnMouseEnter = Image1MouseEnter
  end
  object Label1: TLabel
    Left = 114
    Top = 112
    Width = 53
    Height = 21
    Caption = 'E-mail:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 114
    Top = 208
    Width = 63
    Height = 21
    Caption = 'Lozinka:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object EditEmail: TEdit
    Left = 114
    Top = 147
    Width = 209
    Height = 23
    TabOrder = 0
  end
  object EditLozinka: TEdit
    Left = 114
    Top = 235
    Width = 209
    Height = 23
    PasswordChar = '*'
    TabOrder = 1
  end
  object Registracija: TButton
    Left = 280
    Top = 306
    Width = 99
    Height = 57
    Caption = 'Registracija'
    TabOrder = 2
    OnClick = RegistracijaClick
  end
  object Prijava: TButton
    Left = 104
    Top = 306
    Width = 99
    Height = 57
    Caption = 'Prijava'
    TabOrder = 3
    OnClick = PrijavaClick
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\Kiki\Docum' +
      'ents\Projekt_Joha_Ujevic\Joha_Ujevic.mdb;Persist Security Info=F' +
      'alse'
    LoginPrompt = False
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 96
    Top = 24
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 184
    Top = 24
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 336
    Top = 104
  end
  object Hash1: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 328
    Top = 144
    HashId = 'native.hash.SHA-256'
  end
  object Hash2: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 360
    Top = 200
    HashId = 'native.hash.MD5'
  end
  object Hash3: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 384
    Top = 256
    HashId = 'native.hash.SHA-256'
  end
  object TKorisnici: TADOTable
    Left = 264
    Top = 32
  end
  object XMLDocument1: TXMLDocument
    FileName = 'C:\Users\Kiki\Documents\Projekt_Joha_Ujevic\logovi.xml'
    Left = 56
    Top = 104
    DOMVendorDesc = 'MSXML'
  end
end
