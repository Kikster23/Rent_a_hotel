object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Form5'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 23
    Height = 15
    Caption = 'Ime:'
  end
  object Label2: TLabel
    Left = 24
    Top = 66
    Width = 45
    Height = 15
    Caption = 'Prezime:'
  end
  object Label3: TLabel
    Left = 24
    Top = 116
    Width = 37
    Height = 15
    Caption = 'E-mail:'
  end
  object Label6: TLabel
    Left = 216
    Top = 16
    Width = 43
    Height = 15
    Caption = 'Lozinka:'
  end
  object Label4: TLabel
    Left = 216
    Top = 66
    Width = 22
    Height = 15
    Caption = 'OIB:'
  end
  object Label5: TLabel
    Left = 216
    Top = 116
    Width = 19
    Height = 15
    Caption = 'Tip:'
  end
  object EditIme: TEdit
    Left = 24
    Top = 37
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object EditPrezime: TEdit
    Left = 24
    Top = 87
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object EditEmail: TEdit
    Left = 24
    Top = 137
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object EditLozinka: TEdit
    Left = 216
    Top = 37
    Width = 121
    Height = 23
    PasswordChar = '*'
    TabOrder = 3
  end
  object EditOib: TEdit
    Left = 216
    Top = 87
    Width = 121
    Height = 23
    TabOrder = 4
  end
  object ComboTip: TComboBox
    Left = 216
    Top = 137
    Width = 145
    Height = 23
    ItemIndex = 0
    TabOrder = 5
    Text = 'Korisnik'
    Items.Strings = (
      'Korisnik'
      'Admin')
  end
  object Dodaj: TButton
    Left = 24
    Top = 344
    Width = 125
    Height = 41
    Caption = ' Dodaj novog korisnika'
    TabOrder = 6
    OnClick = DodajClick
  end
  object Obrisi: TButton
    Left = 174
    Top = 344
    Width = 125
    Height = 41
    Caption = 'Obri'#353'i korisnika'
    TabOrder = 7
    OnClick = ObrisiClick
  end
  object Uredi: TButton
    Left = 324
    Top = 344
    Width = 125
    Height = 41
    Caption = 'Uredi korisnika'
    TabOrder = 8
    OnClick = UrediClick
  end
  object Povratak: TButton
    Left = 477
    Top = 372
    Width = 106
    Height = 49
    Caption = 'Povratak'
    TabOrder = 9
    OnClick = PovratakClick
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 176
    Width = 441
    Height = 145
    DataSource = DataSource1
    TabOrder = 10
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Ime'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Prezime'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Email'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'OIB'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Tip'
        Width = 80
        Visible = True
      end>
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
    Left = 464
    Top = 72
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Korisnici'
    Left = 552
    Top = 80
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 536
    Top = 168
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 376
    Top = 24
  end
  object Hash1: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 464
    Top = 32
    HashId = 'native.hash.SHA-256'
  end
  object Hash2: THash
    CryptoLibrary = CryptographicLibrary1
    Left = 520
    Top = 32
    HashId = 'native.hash.MD5'
  end
end
