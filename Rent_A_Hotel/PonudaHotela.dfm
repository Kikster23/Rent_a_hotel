object Form13: TForm13
  Left = 0
  Top = 0
  Caption = 'Form13'
  ClientHeight = 310
  ClientWidth = 678
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object LabelPostotak: TLabel
    Left = 216
    Top = 32
    Width = 145
    Height = 47
    Caption = 'Postotak'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -35
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Brzina1: TButton
    Left = 8
    Top = 183
    Width = 75
    Height = 25
    Caption = '50 kbps'
    TabOrder = 0
    OnClick = Brzina1Click
  end
  object Brzina2: TButton
    Left = 8
    Top = 228
    Width = 75
    Height = 25
    Caption = '100 kbps'
    TabOrder = 1
    OnClick = Brzina2Click
  end
  object Preuzmi: TButton
    Left = 8
    Top = 144
    Width = 153
    Height = 25
    Caption = 'Preuzmi ponudu hotela:'
    TabOrder = 2
    OnClick = PreuzmiClick
  end
  object BezOgranicenja: TButton
    Left = 8
    Top = 267
    Width = 97
    Height = 25
    Caption = 'Bez Ograni'#269'enja'
    TabOrder = 3
    OnClick = BezOgranicenjaClick
  end
  object ProgressBar1: TProgressBar
    Left = 40
    Top = 105
    Width = 569
    Height = 17
    TabOrder = 4
  end
  object Povratak: TButton
    Left = 487
    Top = 228
    Width = 129
    Height = 49
    Caption = 'Povratak'
    TabOrder = 5
    OnClick = PovratakClick
  end
  object IdInterceptThrottler1: TIdInterceptThrottler
    BitsPerSec = 0
    RecvBitsPerSec = 0
    SendBitsPerSec = 0
    Left = 376
    Top = 136
  end
  object Internet: TIdHTTP
    Intercept = IdInterceptThrottler1
    IOHandler = IdSSLIOHandlerSocketOpenSSL1
    OnWork = InternetWork
    OnWorkBegin = InternetWorkBegin
    HandleRedirects = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 520
    Top = 24
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    Intercept = IdInterceptThrottler1
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Method = sslvTLSv1_2
    SSLOptions.SSLVersions = [sslvTLSv1_2]
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 400
    Top = 16
  end
end
