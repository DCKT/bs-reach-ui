[%bs.raw {|require('@reach/menu-button/styles.css')|}];

[%bs.raw {|require('@reach/dialog/styles.css')|}];

[@bs.module] external logo : string = "./logo.svg";

type state = {dialogIsOpen: bool};

type action =
  | ToggleDialog;

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {dialogIsOpen: false},
  reducer: (action, state) =>
    switch (action) {
    | ToggleDialog => ReasonReact.Update({dialogIsOpen: ! state.dialogIsOpen})
    },
  render: self =>
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> ("bs-reach-ui" |> ReasonReact.string) </h2>
      </div>
      <div>
        <h2> ("VisuallyHidden" |> ReasonReact.string) </h2>
        <button>
          <img src="http://placehold.it/20x20" alt="save" />
          <VisuallyHidden> ("test" |> ReasonReact.string) </VisuallyHidden>
        </button>
      </div>
      <hr />
      <div>
        <h2> ("MenuButton" |> ReasonReact.string) </h2>
        <MenuButton.Menu>
          <MenuButton.MenuButton>
            ("Products" |> ReasonReact.string)
          </MenuButton.MenuButton>
          <MenuButton.MenuList>
            <MenuButton.MenuItem onSelect=(() => Js.log("Download"))>
              ("Download" |> ReasonReact.string)
            </MenuButton.MenuItem>
            <MenuButton.MenuLink
              component="a" to_="test" href="https://reach.tech/courses">
              ("Online Courses" |> ReasonReact.string)
            </MenuButton.MenuLink>
            <MenuButton.MenuLink
              to_="test2" component="a" href="https://reach.tech/ui">
              ("Reach UI" |> ReasonReact.string)
            </MenuButton.MenuLink>
          </MenuButton.MenuList>
        </MenuButton.Menu>
        <hr />
        <div>
          <h2> ("Dialog" |> ReasonReact.string) </h2>
          <button onClick=(_event => self.send(ToggleDialog))>
            ("Toggle dialog" |> ReasonReact.string)
          </button>
          <Dialog.Dialog
            isOpen=self.state.dialogIsOpen
            onDismiss=(() => self.send(ToggleDialog))>
            <p> ("hello" |> ReasonReact.string) </p>
          </Dialog.Dialog>
        </div>
        <hr />
        <div>
          <h2> ("WindowSize" |> ReasonReact.string) </h2>
          <WindowSize>
            ...(
                 windowSize =>
                   <div>
                     <p>
                       ("width : " |> ReasonReact.string)
                       (
                         WindowSize.widthGet(windowSize)
                         |> string_of_int
                         |> ReasonReact.string
                       )
                     </p>
                     <p>
                       ("height : " |> ReasonReact.string)
                       (
                         WindowSize.heightGet(windowSize)
                         |> string_of_int
                         |> ReasonReact.string
                       )
                     </p>
                   </div>
               )
          </WindowSize>
        </div>
      </div>
    </div>,
};