[@bs.deriving abstract]
type commonjsProps = {
  className: Js.Nullable.t(string),
  style: Js.Nullable.t(string),
};

module SkipNavLink = {
  [@bs.module "@reach/skip-nav"]
  external reactClass : ReasonReact.reactClass = "SkipNavLink";
  let make = (~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        commonjsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
        ),
      children,
    );
};

module SkipNavContent = {
  [@bs.module "@reach/skip-nav"]
  external reactClass : ReasonReact.reactClass = "SkipNavContent";
  let make = (~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        commonjsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
        ),
      children,
    );
};