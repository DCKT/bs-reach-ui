[@bs.deriving abstract]
type commonjsProps = {
  className: Js.Nullable.t(string),
  style: Js.Nullable.t(string),
  isOpen: bool,
  onDismiss: Js.Nullable.t(unit => unit),
  initialFocusRef: Js.Nullable.t(ReasonReact.reactRef),
};

module Dialog = {
  [@bs.module "@reach/dialog"]
  external reactClass : ReasonReact.reactClass = "Dialog";
  let make =
      (
        ~isOpen: bool,
        ~onDismiss=?,
        ~initialFocusRef=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        commonjsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
          ~isOpen,
          ~onDismiss=Js.Nullable.fromOption(onDismiss),
          ~initialFocusRef=Js.Nullable.fromOption(initialFocusRef),
        ),
      children,
    );
};

module DialogOverlay = {
  [@bs.module "@reach/dialog"]
  external reactClass : ReasonReact.reactClass = "DialogOverlay";
  let make =
      (
        ~isOpen: bool,
        ~onDismiss=?,
        ~initialFocusRef=?,
        ~className=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        commonjsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
          ~onDismiss=Js.Nullable.fromOption(onDismiss),
          ~initialFocusRef=Js.Nullable.fromOption(initialFocusRef),
          ~isOpen,
        ),
      children,
    );
};

[@bs.deriving abstract]
type dialogContentJsProps = {
  className: Js.Nullable.t(string),
  style: Js.Nullable.t(string),
};

module DialogContent = {
  [@bs.module "@reach/dialog"]
  external reactClass : ReasonReact.reactClass = "DialogContent";
  let make = (~className=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        dialogContentJsProps(
          ~className=Js.Nullable.fromOption(className),
          ~style=Js.Nullable.fromOption(style),
        ),
      children,
    );
};