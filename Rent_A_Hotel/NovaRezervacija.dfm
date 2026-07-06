object Form10: TForm10
  Left = 0
  Top = 0
  Caption = 'Form10'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object Label3: TLabel
    Left = 32
    Top = 24
    Width = 75
    Height = 15
    Caption = 'Odaberi hotel:'
  end
  object Label1: TLabel
    Left = 33
    Top = 184
    Width = 19
    Height = 15
    Caption = 'Od:'
  end
  object Label2: TLabel
    Left = 33
    Top = 234
    Width = 18
    Height = 15
    Caption = 'Do:'
  end
  object DBGrid1: TDBGrid
    Left = 32
    Top = 45
    Width = 575
    Height = 124
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = 'Ime'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Adresa'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Broj_soba'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Wi-Fi'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Jacuzzi'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Cijena_Dan'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Cijena_Dan_PDV'
        Width = 110
        Visible = True
      end>
  end
  object DateTimeOd: TDateTimePicker
    Left = 32
    Top = 205
    Width = 153
    Height = 23
    Date = 45908.000000000000000000
    Time = 0.730238958334666700
    TabOrder = 1
  end
  object DateTimeDo: TDateTimePicker
    Left = 32
    Top = 255
    Width = 153
    Height = 23
    Date = 45908.000000000000000000
    Time = 0.730238958334666700
    TabOrder = 2
  end
  object Rezerviraj: TButton
    Left = 32
    Top = 336
    Width = 113
    Height = 49
    Caption = 'Rezerviraj'
    TabOrder = 3
    OnClick = RezervirajClick
  end
  object DBImage1: TDBImage
    Left = 240
    Top = 184
    Width = 368
    Height = 185
    DataField = 'Slika'
    DataSource = DataSource1
    Proportional = True
    Stretch = True
    TabOrder = 4
  end
  object Povratak: TButton
    Left = 464
    Top = 384
    Width = 129
    Height = 49
    Caption = 'Povratak'
    TabOrder = 5
    OnClick = PovratakClick
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
    Left = 552
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    OnCalcFields = ADOTable1CalcFields
    TableName = 'Hoteli'
    Left = 488
    Top = 128
    object ADOTable1Hotel_ID: TAutoIncField
      FieldName = 'Hotel_ID'
      ReadOnly = True
    end
    object ADOTable1Ime: TWideStringField
      FieldName = 'Ime'
      Size = 255
    end
    object ADOTable1Adresa: TWideStringField
      FieldName = 'Adresa'
      Size = 255
    end
    object ADOTable1Broj_soba: TIntegerField
      FieldName = 'Broj_soba'
    end
    object ADOTable1WiFi: TWideStringField
      FieldName = 'Wi-Fi'
      Size = 255
    end
    object ADOTable1Jacuzzi: TWideStringField
      FieldName = 'Jacuzzi'
      Size = 255
    end
    object ADOTable1Cijena_Dan: TIntegerField
      FieldName = 'Cijena_Dan'
    end
    object ADOTable1Slika: TBlobField
      FieldName = 'Slika'
    end
    object ADOTable1Cijena_Dan_PDV: TFloatField
      FieldKind = fkCalculated
      FieldName = 'Cijena_Dan_PDV'
      Calculated = True
    end
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 560
    Top = 112
  end
  object ADOTable2: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Rezervacije'
    Left = 168
    Top = 360
  end
end
