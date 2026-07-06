object Form6: TForm6
  Left = 0
  Top = 0
  Caption = 'Form6'
  ClientHeight = 561
  ClientWidth = 834
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 15
  object Label1: TLabel
    Left = 17
    Top = 16
    Width = 23
    Height = 15
    Caption = 'Ime:'
  end
  object Label6: TLabel
    Left = 191
    Top = 16
    Width = 31
    Height = 15
    Caption = 'Wi-Fi:'
  end
  object Label2: TLabel
    Left = 17
    Top = 72
    Width = 39
    Height = 15
    Caption = 'Adresa:'
  end
  object Label4: TLabel
    Left = 191
    Top = 72
    Width = 39
    Height = 15
    Caption = 'Jacuzzi:'
  end
  object Label3: TLabel
    Left = 17
    Top = 122
    Width = 52
    Height = 15
    Caption = 'Broj soba:'
  end
  object Label5: TLabel
    Left = 191
    Top = 122
    Width = 75
    Height = 15
    Caption = 'Cijena na dan:'
  end
  object EditIme: TEdit
    Left = 17
    Top = 37
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object EditAdresa: TEdit
    Left = 17
    Top = 93
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object EditSoba: TEdit
    Left = 17
    Top = 143
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object EditCijena: TEdit
    Left = 191
    Top = 143
    Width = 121
    Height = 23
    TabOrder = 3
  end
  object Dodaj: TButton
    Left = 17
    Top = 440
    Width = 125
    Height = 41
    Caption = ' Dodaj novi hotel'
    TabOrder = 4
    OnClick = DodajClick
  end
  object Obriši: TButton
    Left = 171
    Top = 440
    Width = 125
    Height = 41
    Caption = 'Obri'#353'i hotel'
    TabOrder = 5
    OnClick = ObrišiClick
  end
  object Uredi: TButton
    Left = 340
    Top = 440
    Width = 125
    Height = 41
    Caption = 'Uredi hotel'
    TabOrder = 6
    OnClick = UrediClick
  end
  object Spremi: TButton
    Left = 501
    Top = 440
    Width = 124
    Height = 41
    Caption = 'Spremi sliku'
    TabOrder = 7
    OnClick = SpremiClick
  end
  object Povratak: TButton
    Left = 679
    Top = 495
    Width = 106
    Height = 49
    Caption = 'Povratak'
    TabOrder = 8
    OnClick = PovratakClick
  end
  object DBImage1: TDBImage
    Left = 517
    Top = 8
    Width = 300
    Height = 231
    DataField = 'Slika'
    DataSource = DataSource1
    Proportional = True
    Stretch = True
    TabOrder = 9
  end
  object ComboWiFi: TComboBox
    Left = 191
    Top = 37
    Width = 121
    Height = 23
    ItemIndex = 0
    TabOrder = 10
    Text = 'Da'
    Items.Strings = (
      'Da'
      'Ne')
  end
  object ComboJacuzzi: TComboBox
    Left = 191
    Top = 93
    Width = 121
    Height = 23
    ItemIndex = 0
    TabOrder = 11
    Text = 'Da'
    Items.Strings = (
      'Da'
      'Ne')
  end
  object DBGrid1: TDBGrid
    Left = 17
    Top = 245
    Width = 512
    Height = 169
    DataSource = DataSource1
    TabOrder = 12
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
        FieldName = 'Adresa'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Broj_soba'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Wi-Fi'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Jacuzzi'
        Width = 80
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Cijena_Dan'
        Width = 80
        Visible = True
      end>
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Hoteli'
    Left = 632
    Top = 256
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
    Left = 712
    Top = 264
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 720
    Top = 368
  end
  object OpenDialog1: TOpenDialog
    Left = 600
    Top = 344
  end
end
