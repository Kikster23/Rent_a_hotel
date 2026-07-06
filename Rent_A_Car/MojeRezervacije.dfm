object Form11: TForm11
  Left = 0
  Top = 0
  Caption = 'Form11'
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
  object Label1: TLabel
    Left = 72
    Top = 24
    Width = 273
    Height = 45
    Caption = 'Moje rezervacije:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 32
    Top = 104
    Width = 457
    Height = 201
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Hotel_ID'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Datum_OD'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Datum_DO'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Ukupna_Cijena'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Ukupna_Cijena_PDV'
        Visible = True
      end>
  end
  object Povratak: TButton
    Left = 432
    Top = 352
    Width = 129
    Height = 49
    Caption = 'Povratak'
    TabOrder = 1
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
    Left = 504
    Top = 56
  end
  object ADOTable1: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    OnCalcFields = ADOTable1CalcFields
    TableName = 'Rezervacije'
    Left = 520
    Top = 128
    object ADOTable1Rezervacija_ID: TAutoIncField
      FieldName = 'Rezervacija_ID'
      ReadOnly = True
    end
    object ADOTable1Korisnik_ID: TWideStringField
      FieldName = 'Korisnik_ID'
      Size = 255
    end
    object ADOTable1Hotel_ID: TWideStringField
      FieldName = 'Hotel_ID'
      Size = 255
    end
    object ADOTable1Datum_OD: TDateTimeField
      FieldName = 'Datum_OD'
    end
    object ADOTable1Datum_DO: TDateTimeField
      FieldName = 'Datum_DO'
    end
    object ADOTable1Ukupna_Cijena: TIntegerField
      FieldName = 'Ukupna_Cijena'
    end
    object ADOTable1Ukupna_Cijena_PDV: TFloatField
      FieldKind = fkCalculated
      FieldName = 'Ukupna_Cijena_PDV'
      Calculated = True
    end
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    Left = 544
    Top = 200
  end
end
