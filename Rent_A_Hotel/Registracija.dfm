object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 394
  ClientWidth = 427
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object Label1: TLabel
    Left = 30
    Top = 16
    Width = 23
    Height = 15
    Caption = 'Ime:'
  end
  object Label2: TLabel
    Left = 30
    Top = 67
    Width = 45
    Height = 15
    Caption = 'Prezime:'
  end
  object Label3: TLabel
    Left = 30
    Top = 128
    Width = 37
    Height = 15
    Caption = 'E-mail:'
  end
  object Label4: TLabel
    Left = 30
    Top = 189
    Width = 43
    Height = 15
    Caption = 'Lozinka:'
  end
  object Label7: TLabel
    Left = 30
    Top = 246
    Width = 22
    Height = 15
    Caption = 'OIB:'
  end
  object EditIme: TEdit
    Left = 30
    Top = 35
    Width = 124
    Height = 23
    TabOrder = 0
  end
  object EditPrezime: TEdit
    Left = 30
    Top = 88
    Width = 124
    Height = 23
    TabOrder = 1
  end
  object EditEmail: TEdit
    Left = 30
    Top = 149
    Width = 124
    Height = 23
    TabOrder = 2
  end
  object EditLozinka: TEdit
    Left = 30
    Top = 210
    Width = 124
    Height = 23
    PasswordChar = '*'
    TabOrder = 3
  end
  object EditOIB: TEdit
    Left = 30
    Top = 267
    Width = 124
    Height = 23
    TabOrder = 4
  end
  object Registiraj: TButton
    Left = 232
    Top = 115
    Width = 137
    Height = 65
    Caption = 'Registriraj se '
    TabOrder = 5
    OnClick = RegistirajClick
  end
  object Povratak: TButton
    Left = 280
    Top = 336
    Width = 89
    Height = 25
    Caption = 'Povratak'
    TabOrder = 6
    OnClick = PovratakClick
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 272
    Top = 32
  end
  object Hash1: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 208
    Top = 24
    HashId = 'native.hash.SHA-256'
  end
  object Hash2: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 344
    Top = 40
    HashId = 'native.hash.MD5'
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Users\Kiki\Docum' +
      'ents\Projekt_Joha_Ujevic\Joha_Ujevic.mdb;Persist Security Info=F' +
      'alse'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 208
    Top = 232
  end
  object TKorisnici: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Korisnici'
    Left = 343
    Top = 176
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    Left = 351
    Top = 264
  end
  object XMLDocument1: TXMLDocument
    FileName = 'C:\Users\Kiki\Documents\Projekt_Joha_Ujevic\logovi.xml'
    Left = 248
    Top = 184
    DOMVendorDesc = 'MSXML'
  end
end
