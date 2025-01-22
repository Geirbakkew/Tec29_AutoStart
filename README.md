Dometic Tec29 modifikasjon for å bli styrt fullt ut av en Victron kontroller.

Etter modifikasjon så trenger ikke Tec29 stå på, dette ordnes av Arduino koden.
Slår en på bryteren så vil automatikken ordne oppstart av kontroll panel og starte gennerator, sjekker om generator svier etter 40 sek og starter sekvens på ny om det ikke gjør, i koden er det lagt opp til 4 forsøk.

Deleliste
Arduino NANO
4 Relemodul 5V
12 til 5v omformer
1000yF condensator for å holde stabil spenning (koblet på 5v og Neg Arduino).

230v Tidsrelé forsinket innkobling (valgfritt kan legge dette i Arduino koden, vanlig 230v rele virker også. Tidsrele ble benyttet da det var det som jeg hadde liggende.)
