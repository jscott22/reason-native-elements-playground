open BsReactNative;

let onAndroid = Platform.os() == Platform.Android;

let boldStyles = Style.(onAndroid ? fontWeight(`Bold) : fontWeight(`Normal));

type headingMode =
  | H1
  | H2
  | H3
  | H4;

let headingStyle = (initial, headingMode) =>
  Style.(
    switch (headingMode) {
    | Some(H1) => [fontSize(Float(60.)), boldStyles, ...initial]
    | Some(H2) => [fontSize(Float(34.)), boldStyles, ...initial]
    | Some(H3) => [fontSize(Float(28.)), boldStyles, ...initial]
    | Some(H4) => [fontSize(Float(22.)), boldStyles, ...initial]
    | None => initial
    }
  );

let fontFamilyStyle = (initial, family) =>
  Style.(
    switch (family) {
    | Some(f) => [fontFamily(f), ...initial]
    | None => initial
    }
  );

let getFontStyles = (~headingMode, ~fontFamily) => {
  let initial = onAndroid ? [Style.fontFamily("sans-serif")] : [];
  initial |. headingStyle(headingMode) |. fontFamilyStyle(fontFamily);
};

let getCombinedStyles = (~userStyles, ~headingMode, ~fontFamily) => {
  let fontStyles = getFontStyles(~headingMode, ~fontFamily);
  Style.(
    switch (userStyles) {
      | Some(s) => concat([s, style(fontStyles)])
      | None => style(fontStyles)
      }
  );
};

let component = ReasonReact.statelessComponent("RNEText");

let make =
    (
      ~style as userStyles=?,
      ~headingMode=?,
      ~fontFamily=?,
      children,
    ) => {
  ...component,
  render: _self =>
    <Text style=(getCombinedStyles(~userStyles, ~headingMode, ~fontFamily))>
      ...children
    </Text>,
};
